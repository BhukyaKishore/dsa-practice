#include <iostream>
#include <vector>
using namespace std;

void printVector(const vector<int>& arr) {
    for (int num : arr)
        cout << num << " ";
    cout << endl;
}
void bubbleSort(vector<int>& nums){
    for(int i=0;i<nums.size()-1;i++){
        for(int j=1;j<nums.size()-i;j++){
            if(nums[j-1]>nums[j]) swap(nums[j-1],nums[j]);
        }        
    }
}


int main() {
    vector<int> arr = {64, 25, 12, 22, 11};

    cout << "Original vector: ";
    printVector(arr);

    bubbleSort(arr);

    cout << "Sorted vector: ";
    printVector(arr);

    return 0;
}
