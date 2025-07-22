#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int>& arr, int st, int end) {
    int pivot = arr[end];
    int i = st - 1;
    for (int j = st; j < end; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[end]);
    return i + 1;
}

void quickSort(vector<int>& arr, int st, int end) {
    if (st < end) {
        int pi = partition(arr, st, end);
        quickSort(arr, st, pi - 1);
        quickSort(arr, pi + 1, end);
    }
}

int main() {
    vector<int> arr = {8, 7, 3, 9, 4, 64, 3, 35, 1, 12,12,121};
    quickSort(arr, 0, arr.size() - 1);
    for (int val : arr)
        cout << val << " ";
    cout << endl;
    return 0;
}
