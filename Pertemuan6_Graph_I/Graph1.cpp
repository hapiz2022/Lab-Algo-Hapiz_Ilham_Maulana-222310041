#include <iostream>
#include <vector>
#include <climits>
#include <cstring>

using namespace std;

int main() {
  int n;
  cout << "Masukkan Jumlah Kota: ";
  cin >> n;
  int** arr = new int*[n];
  for (int i = 0; i < n; i++) {
    cout << "Cost Element Baris Ke-: " << i + 1 << endl;
    arr[i] = new int[n];
    for (int j = 0; j < n; j++) {
      cin >> arr[i][j];
    }
  }
  cout << "Cost List:" << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << "\t" << arr[i][j];
    }
    cout << endl;
  }
  vector<int> path;
  int cost = INT_MAX;
  for (int i = 0; i < n; i++) {
    int temp_cost = 0;
    vector<int> temp_path;
    vector<bool> visited(n, false);

    visited[i] = true;
    temp_path.push_back(i + 1);
    for (int j = 0; j < n - 1; j++) {
      int curr_node = temp_path.back() - 1;
      int min_cost = INT_MAX;
      int next_node = 0;
      for (int k = 0; k < n; k++) {
        if (!visited[k] && arr[curr_node][k] < min_cost) {
          min_cost = arr[curr_node][k];
          next_node = k;
        }
      }
      temp_cost += min_cost;
      visited[next_node] = true;
      temp_path.push_back(next_node + 1);
    }
    temp_cost += arr[temp_path.back() - 1][i];
    temp_path.push_back(i + 1);
    if (temp_cost < cost) {
      cost = temp_cost;
      path = temp_path;
    }
  }
  cout << endl << "Jalur Terpendek:" << endl;
  for (int i = 0; i < n; i++) {
    if (i == n - 1)
      cout << path[i] << endl;
    else
      cout << path[i] << "--->";
  }
  cout << endl << endl << "Minimum Cost: " << cost << endl;

  // Clean up dynamically allocated memory
  for (int i = 0; i < n; i++) {
    delete[] arr[i];
  }
  delete[] arr;

  return 0;
}
