#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
  int i, j, tmp;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        tmp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = tmp;
      }
    }
  }
}

int main() {
  int array[100], n, i;
  cout << "Masukkan banyak elemen: ";
  cin >> n;
  cout << "Masukkan nilai: \n";
  for (i = 0; i < n; i++) {
    cin >> array[i];
  }
  cin.ignore();
  bubbleSort(array, n);
  cout << "Hasil pengurutan dengan algoritma bubble sort:\n";
  for (i = 0; i < n; i++) {
    cout << array[i] << " ";
  }

  cout << "\n\nPress any key to exit..." << endl;
  getchar(); 
  return 0;
}
