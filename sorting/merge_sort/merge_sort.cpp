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

void merge_sort(vector<int>& arr, size_t first, size_t last) {
    size_t size = last - first + 1;
    if (size < 2) return;

    auto left_size = size / 2;
    auto left_first = first;
    auto right_first = first + left_size;

    merge_sort(arr, left_first, right_first - 1);
    merge_sort(arr, right_first, last);

    vector<int> buf;
    buf.reserve(size);
    auto left_last = left_first + left_size;
    while (left_first < left_last && right_first <= last) {
        if (arr[left_first] < arr[right_first]) {
            buf.push_back(arr[left_first]);
            ++left_first;
        }
        else {
            buf.push_back(arr[right_first]);
            ++right_first;
        }
    }
    if (left_first < left_last) {
        buf.insert(buf.end(), arr.begin() + left_first, arr.begin() + left_last);
    }
    else if (right_first <= last) {
        buf.insert(buf.end(), arr.begin() + right_first, arr.begin() + last + 1);
    }
    move(buf.begin(), buf.end(), arr.begin() + first);
}

void merge_sort(vector<int>& arr) {
    merge_sort(arr, 0, arr.size() - 1);
}

int main()
{
    vector<int> arr{ 1, 4, 3, 5, 6, 2, 2 };
    merge_sort(arr);
    printVector(arr);

  return 0;
}