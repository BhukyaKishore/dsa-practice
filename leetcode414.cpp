// Given an integer array nums, return the third distinct maximum number in this array. If the third maximum does not exist, return the maximum number.

// Example 1:

// Input: nums = [3,2,1]
// Output: 1
// Explanation:
// The first distinct maximum is 3.
// The second distinct maximum is 2.
// The third distinct maximum is 1.
// Example 2:

// Input: nums = [1,2]
// Output: 2
// Explanation:
// The first distinct maximum is 2.
// The second distinct maximum is 1.
// The third distinct maximum does not exist, so the maximum (2) is returned instead.
// Example 3:

// Input: nums = [2,2,3,1]
// Output: 1
// Explanation:
// The first distinct maximum is 3.
// The second distinct maximum is 2 (both 2's are counted together since they have the same value).
// The third distinct maximum is 1.



#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        if(nums.size()==2){
            if(nums[0]>nums[1]) return nums[0];
            else return nums[1];
        }
        long max=LONG_MIN,maxer=LONG_MIN ,maxest=LONG_MIN,count=0;
        for(int val:nums){
            if(val>maxest){
                max=maxer;
                maxer=maxest;
                maxest=val;
            }else if(val<maxest && val>maxer){
                max=maxer;
                maxer=val;
            }else if(val<maxest && val<maxer && val>=max){
                max=val;
            }
        }
        if((max>LONG_MIN)) return max;
        else return maxest;
    }
};

int main(){
    vector<int> vec={1,2,2,5,3,5};
    Solution s;
    cout<<s.thirdMax(vec)<<endl;
    
    return 0;
}