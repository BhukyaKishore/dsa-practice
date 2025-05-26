#include <iostream>
#include <vector>
using namespace std;
class Solution {
    public:
        int maxProfit(vector<int>& nums) {
            int buy=nums[0],profit=0;
            for(int i=1;i<nums.size();i++){
                if(nums[i]>buy){
                    if(profit<(nums[i]-buy)){
                        profit=nums[i]-buy;
                    }
                }
                if(buy>nums[i]){
                    buy=nums[i];
                }
            }
            return profit;
        }
    };
int main(){
    vector<int> vec={7,1,5,3,6,4};
    Solution s;
    cout<<s.maxProfit(vec)<<endl;
    return 0;
}