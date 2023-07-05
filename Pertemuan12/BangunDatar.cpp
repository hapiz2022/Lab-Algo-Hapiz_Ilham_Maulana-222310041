#include <iostream>

using namespace std;

// parent class
class BangunDatar {
	protected:
		int lebar, tinggi;
		
	public:
		void setValue(int a, int b) {
			lebar = a;
			tinggi = b;
		}
};

// child class
class PersegiPanjang: public BangunDatar {
	public:
		int getValue() {
			return (lebar * tinggi);
		}
};

// child class
class Segitiga: public BangunDatar {
	public:
		int getValue() {
			return (lebar * tinggi / 2);
		}
};

// main program
int main() {
	// instance object
	PersegiPanjang pp;
	Segitiga s;
	
	//	initiate value
	pp.setValue(4, 5);
	s.setValue(10, 5);
	
	// return value
	cout << pp.getValue() << endl;
	cout << s.getValue() << endl;
	
	return 0;
}
