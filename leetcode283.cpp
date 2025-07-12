// Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

// Note that you must do this in-place without making a copy of the array.

// Example 1:

// Input: nums = [0,1,0,3,12]
// Output: [1,3,12,0,0]
// Example 2:

// Input: nums = [0]
// Output: [0]

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int to=0,from=0;
        while(from<nums.size() && to<nums.size()){
            if(nums[to]==0 && nums[from] !=0){
                nums[to]=nums[from];
                nums[from]=0;
            }
            if(nums[to]!=0) to++;
            from++;
        }
        while(to<nums.size()){
            nums[to++]=0;
        }
    }
}s;

int main(){
    vector<int> vec={0,1,0,3,12}; 
    s.moveZeroes(vec);
    for(int val:vec){
        cout<<val<<" ";
    }
    
    return 0;
}