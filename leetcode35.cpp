// Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

// You must write an algorithm with O(log n) runtime complexity.

// Example 1:

// Input: nums = [1,3,5,6], target = 5
// Output: 2
// Example 2:

// Input: nums = [1,3,5,6], target = 2
// Output: 1
// Example 3:

// Input: nums = [1,3,5,6], target = 7
// Output: 4

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums[0]>=target) return 0;
        if(nums[nums.size()-1]<target) return nums.size();
        if(nums[nums.size()-1]==target) return nums.size()-1;
        int st=0,end=nums.size()-1,mid=0;;
        while(st<end){
            mid=(st+end)/2;
            if(nums[mid]<target && nums[mid+1]>target) return mid+1;
            if(nums[mid]==target || ( nums[mid]>target && nums[mid-1]<target )){
                return mid;
            }else if(nums[mid]<target){
                st=mid;
            }else{
                end=mid;
            }
        }
        return-1;
    }
}s;

int main(){
    vector<int> vec={1,3,5,6};
    int target=5;
    cout<<s.searchInsert(vec,5)<<endl;    
    return 0;
}