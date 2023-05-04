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

vector<int> quickSort1(vector<int> arr) {
  int pivot = arr[0];
  vector<int> result(arr.size());
  int i = 0, j = arr.size() - 1;
  for(int el : arr) {
    if (el < pivot) {
      result[i] = el;
      ++i;
    } else if (el > pivot) {
      result[j] = el;
      --j;
    }
  }
  while (i <= j) {
    result[i] = pivot;
    ++i;
  }
  return result;
}

void quickSort2(vector <int> &arr) {
  if (arr.size() <= 1) {
    return;
  }
  vector<int> left, right;
  int pivot = arr[0];
  for(int el : arr) {
    if (el < pivot) {
      left.push_back(el);
    } else if (el > pivot) {
      right.push_back(el);
    }
  }
  quickSort2(left);
  quickSort2(right);
  for(int i = 0; i < right.size(); ++i) {
    arr[arr.size() - right.size() + i] = right[i];
  }
  for(int i = 0; i < arr.size() - right.size(); ++i) {
    arr[i] = i < left.size() ? left[i] : pivot;
  }
  printVector(arr);
}

void Swap(int& a, int& b) {
  int buf = a;
  a = b;
  b = buf;
}

void quickSort3(vector <int> &arr, int first = 0, int last = 0) {
  if (last == 0) {
    last = arr.size();
  }
  if (last - first <= 1) return;
  int pivot = arr[first];
  int j = first;
  for (int i = first; i < last; ++i) {
      if (arr[i] < pivot) {
        Swap(arr[j], arr[i]);
        ++j;
      }
  }
  if (j == 0) {
    ++j;
  }
  quickSort3(arr, first, j);
  quickSort3(arr, j, last);
  for (int i = first; i < last; ++i) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

void quickSort(vector<int>& arr) {
    if (arr.size() <= 1) return;
    vector<int> right;
    vector<int> left;

    int pivot = arr[0];
    for (auto el : arr) {
        if (el < pivot) {
            left.push_back(el);
        }
        else if (el > pivot) {
            right.push_back(el);
        }
    }
    quickSort(left);
    quickSort(right);
    int right_board = 0;
    for (int i = right.size() - 1; i >= 0; --i) {
        right_board = arr.size() - right.size() + i;
        arr[right_board] = right[i];
    }
    for (int i = 0; i < left.size(); ++i) {
        arr[i] = left[i];
    }
    for (int i = left.size(); i < right_board; ++i) {
        arr[i] = pivot;
    }
}

int main()
{
  std::vector<int> v{ 5, 8, 1, 3, 7, 9, 2 };
  quickSort(v);
  printVector(v);
  return 0;
}