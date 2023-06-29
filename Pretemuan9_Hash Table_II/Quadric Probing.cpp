/**
	* Program Hashtable dengan OpenAddressing
	* Penampung data menggunakan array
	* Tipe implementasi menggunakan Linear Probing
	* Popolasi data menggunakan fungsi random
*/

#include<iostream>
#include<math.h>
#include<ctime>
#include<cstdlib>

using namespace std;

// asumsi menggunakan array dengan limit 1024
int storage[1024];
int i = 0;
int hdt_boundary;

void add_quadric_probing(int n) {
	bool inserted = false;
	int hash;
	i = 0;
	
	while( (!inserted) && (i < hdt_boundary) ) {
		hash = (n % hdt_boundary) + (i*i);
		
		if(storage[hash] == 0) {
			storage[hash] = n;
			inserted = true;
		} else {
			++i;
			cout << "Terjadi tabrakan di " << hash << endl;
		}
	}
	
	if(i == 0) {
		cout << "Langsung" << endl;
	}
	
	cout << "Isi hash[" << hash << "] dengan " << n << endl;
	cout << "=============================================" << endl;
}

int prima_atas(int n) {
	if(n % 2 == 0) {
		n = n + 1;
	} else {
		n = n + 2;
	}
	
	bool ketemu = false;
	
	while(!ketemu) {
		bool prima = true;
		if(n % 2 == 0) {
			prima = false;
		} else {
			int i = 3;
			while (prima == true && i <= sqrt(n)) {
				if(n % i == 0) {
					prima = false;
				}
				i = i + 2;
			}
		}
		if(prima) {
			ketemu = true;
		} else {
			n = n + 2;
		}
	}
	return n;
}

int prima_bawah() {
	int n = hdt_boundary;
	if(n % 2 == 0) {
		n = n - 1;
	} else {
		n = n - 2;
	}
	
	bool ketemu = false;
	while(!ketemu) {
		bool prima = true;
		if(n % 2 == 0) {
			prima = false;
		} else {
			int i = 3;
			while(prima == true && i <= sqrt(n)) {
				if(n % i == 0) {
					prima = false;
				}
				i = i + 2;
			}
		}
		if(prima) {
			ketemu = true;
		} else {
			n = n -2;
		}
	}
	return n;
}

void print(int n) {
	cout << endl;
	cout << "Output Program : " << endl;
	
	for(int a = 0; a < n; ++a) {
		cout << "hash[" << a << "] = " << storage[a] << endl;	
	}
}

int getRandomNumberFromRange(int min, int max) {
	return min + (rand() % (max-min) );
}

int main() {
	int n, random_number;
	char pilihan;
	string cara;
	
	// panggil fungsi ini agar generate random data tidak sama terus
	srand((unsigned)time(0));
	
	cout << "Masukan jumlah data : ";
	cin >> n;
	
	cout << "\n\nProses pemasukan data ke hashtable" << endl;
	
	// tentukan batas |T|
	hdt_boundary = prima_atas(n);
	
	for(int a = 0; a < n; ++a) {
		random_number = getRandomNumberFromRange(0,n);
		add_quadric_probing(random_number);
	}
	
	// operasi untuk print
	print(n);
	cout << "h(k) = (k mod" << hdt_boundary << ") + i*i " << endl; 
}
