#include <iostream>
using namespace std;

void swap(int arr[], int pos1, int pos2) {
  int temp;
  temp = arr[pos1];
  arr[pos1] = arr[pos2];
  arr[pos2] = temp;
}

int partition(int arr[], int low, int high, int pivot) {
  int i = low;
  int j = low;
  while (i <= high) {
    if (arr[i] > pivot) {
      i++;
    } else {
      swap(arr, i, j);
      i++;
      j++;
    }
  }
  return j - 1;
}

void quickSort(int arr[], int low, int high) {
  if (low < high) {
    int pivot = arr[high];
    int pos = partition(arr, low, high, pivot);
    quickSort(arr, low, pos - 1);
    quickSort(arr, pos + 1, high);
  }
}

void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    cout << arr[i] << "\t";
  }
  cout << endl;
}

int main() {
  int n;
  cout << "=== Quick Sort ===" << endl;
  cout << "\nEnter the size of the array: ";
  cin >> n;
  int *arr = new int[n];
  cout << "Enter " << n << " numbers into the array:" << endl;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  cout << "Unsorted array: ";
  printArray(arr, n);
  quickSort(arr, 0, n - 1);
  cout << "Sorted array: ";
  printArray(arr, n);
  cin.ignore();
  cout << "\n\nPress any key to exit..." << endl;
  getchar();
  return 0;
}
