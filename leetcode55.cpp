#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    // hear we are tracking two variable maxreach and index index increment at every ittaraton and update maxreach with maximum value of 
    // privios maxreach and maxreach from current index element
    // at centain point maxreach cross lenth need to travel then return true
    //if index crossed maxreach means we can go to that point but but our index by every ittartion so we can't go further so return false
        bool canJump(vector<int>& nums) {
            int index = 0, maxReach = 0;
            while (index <= maxReach) {
                maxReach = max(maxReach, index + nums[index]);
                if (maxReach >= nums.size() - 1) return true;
                index++;
            }
            return false;
        }
        //same approch from back side
        bool anotherapproch(vector<int>& nums) {
            int goal = nums.size() - 1;
            for (int i = nums.size() - 2; i >= 0; i--) {
                if (i + nums[i] >= goal) {
                    goal = i;
                }
            }
            return goal == 0;        
        }
        //my approch for that same problem
        bool myapproch(vector<int>& nums){
            int maxreach=0;
            for (int i = 0; i < nums.size(); i++)
            {
                if(maxreach>=nums.size()) return true;
                maxreach=max(maxreach,i+nums[i]);
                if(i>maxreach) return false;
            }
            return 0;
        }
        
};

int main(){
    vector<int> vec={3,0,2,0,5,1};
    Solution s;
    cout<<s.canJump(vec)<<endl;
    cout<<s.anotherapproch(vec)<<endl;
    cout<<s.myapproch(vec)<<endl;
    return 0;
}