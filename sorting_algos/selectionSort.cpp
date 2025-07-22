#include <iostream>
#include <vector>
using namespace std;

void selectionSort2(vector<int>& nums){
    for(int i=0;i<nums.size()-1;i++){
        int min_index=i;
        for(int j=i+1;j<nums.size();j++){
            if(nums[j]<nums[min_index]) min_index=j;
        }
        if(min_index!=i)swap(nums[min_index],nums[i]);
    }
}

void printVector(const vector<int>& arr) {
    for (int num : arr)
        cout << num << " ";
    cout << endl;
}

int main() {
    vector<int> arr = {64, 25, 12, 22, 11};

    cout << "Original vector: ";
    printVector(arr);

    selectionSort2(arr);

    cout << "Sorted vector: ";
    printVector(arr);

    return 0;
}
