#include <iostream>
#include <vector>
using namespace std;

/*
Input: nums = [3,2,2,3], val = 3
Output: 2, nums = [2,2,_,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 2.
It does not matter what you leave beyond the returned k (hence they are underscores).


Input: nums = [0,1,2,2,3,0,4,2], val = 2
Output: 5, nums = [0,1,4,0,3,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums containing 0, 0, 1, 3, and 4.
Note that the five elements can be returned in any order.
It does not matter what you leave beyond the returned k (hence they are underscores).
*/

class Solution{
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0,j=nums.size()-1;
        while (i<=j )
        {
            while(nums[j]==val && nums.size()>1){
                nums.pop_back();
                j--;
            }
            if(nums[i]==val){
                nums[i]=nums[j];
                nums.pop_back();
                j--;
            }else{
                i++;
            }
        }
        return nums.size();
    }
};

int main(){
    vector<int> nums={2,2,3};
    int val=2;
    Solution s;
    cout<<s.removeElement(nums,val)<<endl;
    for(int val:nums){
        cout<<" "<<val;
    }
    
    return 0;
}