#include <cstdlib>
#include <iostream>
#define TABLE_SIZE 5
using namespace std;

enum EntryType { LEGITIMATE, EMPTY };

struct HashTableEntry {
  int element;
  enum EntryType info;
};

struct HashTable {
  int size;
  HashTableEntry *table;
};

int HashFunc1(int key, int size) { return key % size; }
int HashFunc2(int key, int size) { return (key * size - 1) % size; }

HashTable *initializeTable(int size) {
  HashTable *hashTable;
  if (size < TABLE_SIZE) {
    cout << "Ukuran Tabel Terlalu Kecil" << endl;
    return NULL;
  }
  hashTable = new HashTable;
  if (hashTable == NULL) {
    cout << "Kehabisan Ruang" << endl;
    return NULL;
  }
  hashTable->size = size;
  hashTable->table = new HashTableEntry[hashTable->size];
  if (hashTable->table == NULL) {
    cout << "Ukuran Tabel Terlalu Kecil" << endl;
    return NULL;
  }
  for (int i = 0; i < hashTable->size; i++) {
    hashTable->table[i].info = EMPTY;
    hashTable->table[i].element = NULL;
  }
  return hashTable;
}

int SearchKey(int key, HashTable *hashTable) {
  int hashValue = HashFunc1(key, hashTable->size);
  int stepSize = HashFunc2(key, hashTable->size);
  while (hashTable->table[hashValue].info != EMPTY &&
         hashTable->table[hashValue].element != key) {
    hashValue = (hashValue + stepSize) % hashTable->size;
  }
  return hashValue;
}

void Insert(int key, HashTable *hashTable) {
  int position = SearchKey(key, hashTable);
  if (hashTable->table[position].info != LEGITIMATE) {
    hashTable->table[position].info = LEGITIMATE;
    hashTable->table[position].element = key;
  }
}

void display(HashTable *hashTable) {
  for (int i = 0; i < hashTable->size; i++) {
    int element = hashTable->table[i].element;
    if (!element)
      cout << "Posisi: " << i + 1 << " Elemen: Null" << endl;
    else
      cout << "Posisi: " << i + 1 << " Elemen: " << element << endl;
  }
}

HashTable *Rehash(HashTable *hashTable) {
  int size = hashTable->size;
  HashTableEntry *table = hashTable->table;
  hashTable = initializeTable(2 * size);
  for (int i = 0; i < size; i++) {
    if (table[i].info == LEGITIMATE)
      Insert(table[i].element, hashTable);
  }
  free(table);
  return hashTable;
}

int main() {
  int value, tableSize, position, i = 1;
  int choice;
  HashTable *hashTable;
  while (1) {
    cout << "===========DOUBLE HASHING===========" << endl;
    cout << "====================================" << endl;
    cout << "1. Inisialisasi ukuran tabel" << endl;
    cout << "2. Memasukkan elemen ke dalam tabel" << endl;
    cout << "3. Menampilkan Tabel Hash" << endl;
    cout << "4. Rehash Tabel Hash" << endl;
    cout << "5. Keluar" << endl;
    cout << "Masukkan pilihan: ";

    cin >> choice;
    switch (choice) {
    case 1:
      cout << "Masukkan ukuran Tabel Hash: ";
      cin >> tableSize;
      hashTable = initializeTable(tableSize);
      break;
    case 2:
      if (i > hashTable->size) {
        cout << "Tabel Penuh, Lakukan Rehash pada tabel" << endl;
        continue;
      }
      cout << "Masukkan elemen yang akan dimasukkan: ";
      cin >> value;
      Insert(value, hashTable);
      i++;
      break;
    case 3:
      display(hashTable);
      break;
    case 4:
      hashTable = Rehash(hashTable);
      break;
    case 5:
      exit(1);
    default:
      cout << "\nMasukkan pilihan yang benar\n";
    }
  }
  return 0;
}
