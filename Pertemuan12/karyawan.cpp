#include <iostream>

using namespace std;

class Karyawan {
	private:
		int gaji;
		
	public:
		void setGaji(int s) {
			gaji = s;
		}
		
		int getGaji() {
			return gaji;
		}
};

int main() {
	Karyawan myKry;
	myKry.setGaji(5000000);
	cout << myKry.getGaji();
	
	return 0;
}
