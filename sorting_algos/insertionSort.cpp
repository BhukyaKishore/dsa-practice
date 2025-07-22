#include<iostream>
#include<vector>
using namespace std;
void insertionSort(vector<int>& nums){
    for(int i=1;i<nums.size();i++){
        int n=nums[i];
        int j=i;
        while(nums[j-1]>n && j>0){
            nums[j]=nums[j-1];
            j--;
        }
        nums[j]=n;
    }
}
int main(){
    vector<int> s={8,7,3,9,4,64,3,35,1,12};
    insertionSort(s);
    for(auto val:s){
        cout<<val<<" ";
    }
    return 0;
}