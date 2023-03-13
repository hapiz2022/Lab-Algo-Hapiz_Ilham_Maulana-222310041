#include <iostream>                                      // memungkinkan program untuk menggunakan input dan output (I/O) standar C++
using namespace std;                                     // Menggunakan namespace std untuk menghindari penulisan
                                                         // std:: sebelum setiap kali menggunakan objek atau fungsi
                                                         // dari library standard

void swap(int arr[], int pos1, int pos2) {               // Mendefinisikan fungsi swap yang menerima tiga
											             // parameter, yaitu array 'arr', posisi elemen pertama
											             // 'pos1', dan posisi elemen kedua 'pos2'
  int temp;              					             // menetapkan variable temp dengan tipe data int
  temp = arr[pos1];      					             // inisialisasi value temp dengan arr[pos1]
  arr[pos1] = arr[pos2]; 					             // menukar value arr[pos1] dengan arr[pos2]
  arr[pos2] = temp;      					             // menetapkan value arr[pos2] pada variable temp
}
int partition(int arr[], int low, int high, int pivot) { // Mendefinisikan fungsi partition yang menerima
														 // empat parameter, yaitu array 'arr', batas bawah
														 // 'low', batas atas 'high', dan nilai pivot yang
														 // digunakan untuk membagi array menjadi dua bagian
  int i = low;                                           // menetapkan variable i dengan tipe data int dengan value pada
                                                         // variable low
  int j = low;                                           // menetapkan variable j dengan tipe data int dengan value pada
                                                         // variable low
  while (i <= high) {                                    // looping dengan kondisi value i kurang sama dengan value high
    if (arr[i] > pivot) {                                // if statement jika arr[i] lebih besar dari value pivot
      i++;       		                                 // menambahkan value i + 1
    } else {     		                                 // jika arr[i] TIDAK lebih besar dari value pivot
      swap(arr, i, j);                                   // memanggil fungsi swap untuk menukar arr pada i menjadi j
      i++;     		                                     // menambahkan value i + 1
      j++;     		                                     // menambahkan value j + 1
    }
  }
  return j - 1;                                          // mengembalikan nilai j-1 yang menandakan bahwa elemen terakhir
                                                         // yang lebih kecil dari pivot berada pada posisi j-1
}
void quickSort(int arr[], int low, int high) {  		 // Mendefinisikan fungsi quickSort yang menerima tiga
														 // parameter, yaitu array 'arr', 'low', dan 'high'
  if (low < high) {        					    		 // if statement jika low lebih kecil dari high
    int pivot = arr[high]; 					    		 // menetapkan variable pivot dengan tipe data int
														 // dengan value pada arr[high]
    int pos = partition(arr, low, high, pivot);  		 // menetapkan variable pos dengan tipe data int
														 // dan memanggil fungsi partition
    quickSort(arr, low, pos - 1); 						 // Fungsi ini akan memanggil dirinya sendiri secara rekursif
														 // untuk mengurutkan elemen yang lebih kecil dari pivot.
    quickSort( arr, pos + 1, high); 					 // Fungsi ini akan memanggil dirinya sendiri secara rekursif
														 // untuk mengurutkan elemen yang lebih besar dari pivot.
  }
}
int main() { 											 // fungsi utama pada program C++
  int n;     											 // menetapkan variable n dengan tipe data int
  cout << "Tentukan panjang array : ";  				 // menampilkan output
  cin >> n;   											 // input dari user dan memasukkan valuenya pada variable n
  int *arr = new int[n];								 // inisialisasi array arr dengan value n
  for (int i = 0; i < n; i++) { 						 // looping sebesar n
    cin >> arr[i];										 // input dari user dan memasukan valuenya ke arr[i]
  }
  quickSort(arr, 0, n - 1); 							 // memanggil fungsi quicksort()  untuk mengurutkan
														 // elemen yang lebih kecil.
  cout << "Berikut adalah array yang telah di sortir: "; // menampilkan output
  for (int i = 0; i < n; i++) {                          // looping sebesar n
    cout << arr[i] << "\t"; 							 // menampilan output arr[i] dan memberikan jarak
														 // antara text dengan \t
  }
  return 0;												 // end of program to 0
}