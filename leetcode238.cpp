#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        vector<int> productExceptSelf(vector<int>& nums) {
            int totalproduct=1;
            vector<int> answer;
            for(int i=0;i<nums.size();i++){
                if(nums[i]!=0){
                    totalproduct*=nums[i];
                }
            }
            for(int i=0;i<nums.size();i++){
                if(nums[i]!=0){
                    answer.push_back(totalproduct/nums[i]);
                }else{
                    answer.push_back(totalproduct);
                }
            }
            return answer;
        }
    };

int main(){
    vector<int> vec={1,2,3,4};
    Solution s;
    vector<int> ans=s.productExceptSelf(vec);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    
    
    return 0;
}