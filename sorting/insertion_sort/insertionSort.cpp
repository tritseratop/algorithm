#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void printVector(const vector<int>& v) {
  for(int el : v) {
    cout << el << " ";
  }
  cout << endl;
}

void insertionSort1(vector<int> arr) {
  for(int i = 1; i < arr.size(); ++i) {
      for (int j = i; j > 0; --j) {
        if (arr[j] < arr [j - 1]) {
          swap(arr[j], arr [j - 1]);
        }
      }
    printVector(arr);
  }
}

void insertionSort2(vector<int> arr) {
  for(int i = 1; i < arr.size(); ++i) {
    if (arr[i] < arr[i-1]) {
      int value = arr[i];
      int j = i - 1;
      while(j >= 0 && value < arr[j]) {
        arr[j+1] = arr[j];
        --j;
      }
      arr[j + 1] = value;
    }
    printVector(arr);
  }
}

void insertionSort3(vector<int> v) {
    for (int i = 1; i < v.size(); ++i) {
        int value = v[i];
        int j = i - 1;
        while (j >= 0 && value < v[j]) {
            v[j + 1] = v[j];
            --j;
        }
        v[j + 1] = value;
    }
    printVector(v);
}


int main()
{
  insertionSort1({1, 4, 3, 5, 6, 2, 2});

  return 0;
}