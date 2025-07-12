// Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

// If target is not found in the array, return [-1, -1].

// You must write an algorithm with O(log n) runtime complexity.

// Example 1:

// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]
// Example 2:

// Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]
// Example 3:

// Input: nums = [], target = 0
// Output: [-1,-1]

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> k={-1,-1};
        if(nums.size()==1 && nums[0]==target){
            k[0]=0;
            k[1]=0;
            return k;
        }
        if(nums.size()<2) return k;
        if(nums[0]>target) return k;
        if(nums[nums.size()-1]<target) return k;
        if(nums[0]==target) {k[0]=0;}
        if(nums[nums.size()-1]==target) {k[1]=nums.size()-1;}
        if(k[0]!=-1 && k[1]!=-1){
            return k;
        }
        int st=1,end=nums.size()-1,mid=0;
        while(st<=end && st>0){
            mid=st+(end-st)/2;
            if(nums[mid]==target && nums[mid-1]<target){
                k[0]=mid;
                break;
            }else if(nums[mid]<target){
                st=mid+1;
            }else{
                end=mid-1;
            }
        }
        // cout<<k[0]<<" "<<k[1]<<endl;
        st=0,end=nums.size()-2,mid=0;
        while(st<=end && end<nums.size()-1){
            mid=st+(end-st)/2;
            if(nums[mid]==target && nums[mid+1]>target){
                k[1]=mid;
                break;
            }else if(nums[mid]>target){
                end=mid-1;
            }else{
                st=mid+1;
            }
        }
        // cout<<k[0]<<" "<<k[1]<<endl;
        if(k[0]==-1 && k[1]!=-1){
            k[0]=k[1];
            return k;
        }else if(k[1]==-1 && k[0]!=-1){
            k[1]=k[0];
            return k;
        }else{
            return k;
        }
    }
}s;

int main(){
    vector<int> vec={5,7,7,8,8,10};
    int target=6;
    vector<int> k=s.searchRange(vec,target);
    cout<<k[0]<<" "<<k[1]<<endl;
    return 0;
}