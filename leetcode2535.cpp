// You are given a positive integer array nums.

// The element sum is the sum of all the elements in nums.
// The digit sum is the sum of all the digits (not necessarily distinct) that appear in nums.
// Return the absolute difference between the element sum and digit sum of nums.

// Note that the absolute difference between two integers x and y is defined as |x - y|.

 

// Example 1:

// Input: nums = [1,15,6,3]
// Output: 9
// Explanation: 
// The element sum of nums is 1 + 15 + 6 + 3 = 25.
// The digit sum of nums is 1 + 1 + 5 + 6 + 3 = 16.
// The absolute difference between the element sum and digit sum is |25 - 16| = 9.
// Example 2:

// Input: nums = [1,2,3,4]
// Output: 0
// Explanation:
// The element sum of nums is 1 + 2 + 3 + 4 = 10.
// The digit sum of nums is 1 + 2 + 3 + 4 = 10.
// The absolute difference between the element sum and digit sum is |10 - 10| = 0.


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int sum=0,digitsum=0;
        for(int val:nums){
            sum+=val;
            if(val<10){
                digitsum+=val;
            }else{
                int k=val;
                while(k>0){
                    digitsum+=k%10;
                    k/=10;
                }
            }
        }
        return abs(sum-digitsum);
    }
};

int main(){
    vector<int> vec={1,9,9,1999,2000,2000,2000};
    Solution s;
    cout<<s.differenceOfSum(vec)<<endl;
    
    return 0;
}