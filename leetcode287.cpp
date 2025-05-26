#include<iostream>
#include <algorithm>
#include<vector>
using namespace std;

class Solution{
    public:
    int removeduplicate(vector<int>&  nums){
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]){
                return nums[i];
            }
        }
        return -1;  
    }
// Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
// There is only one repeated number in nums, return this repeated number.
// You must solve the problem without modifying the array nums and using only constant extra space.
    int optduplicate(vector<int>& nums){
        int slow=nums[0];
        int fast=nums[0];
        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
        }while(slow!=fast);
        slow=nums[0];
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
    }
};

int main(){
    Solution s;
    vector<int> nums={3,1,1,4,5};
    cout<<s.optduplicate(nums)<<endl;
    return 0;
}