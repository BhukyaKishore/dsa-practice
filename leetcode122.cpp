#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int maxProfit(vector<int>& nums) {
            //only one simple rule if privios element grater then it just update buy because it's best price
            //privious elemrnt is less then it then sell and make profit and mark it as new buy for next sells
            int buy=nums[0],sell=0,profit=0;
            for(int i=1;i<nums.size();i++){
                if(nums[i]<=nums[i-1]){
                    buy=nums[i];
                }else{
                    sell=nums[i];
                    profit+=(sell-buy);
                    // cout<<"buy: "<<buy<<" sell: "<<sell<<" profit: "<<profit<<endl;
                    buy=nums[i];
                }
            }
            return profit;
        }
}s;

int main(){
    // vector<int> vec={1,2,3,4,5};
    // vector<int> vec={7,1,5,3,6,4};
    // vector<int> vec={7,6,4,3,1};
    vector<int> vec={7,1,5,7,3,6,4};
    cout<<s.maxProfit(vec)<<endl;
    
    return 0;
}