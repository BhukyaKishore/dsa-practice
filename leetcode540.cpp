#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int singleNonDuplicate(vector<int>& nums) {
            if(nums.size()==1){
                return nums[0];
            }
            if(nums[0]!=nums[1]){
            return nums[0];
            }
            if(nums[nums.size()-1]!=nums[nums.size()-2]){
                return nums[nums.size()-1];
            }   
            int st=1,end=nums.size()-2;
            while(st<=end){
                int mid=st+(end-st)/2;
                // cout<<nums[mid]<<endl;
                if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]){
                    return nums[mid];
                }else{
                    if(nums[mid-1]==nums[mid]){
                        if((mid-1)%2==0){
                            st=mid+1;
                        }else{
                            end=mid-1;
                        }
                    }else{
                        if((mid)%2==0){
                            st=mid+1;
                        }else{
                            end=mid;
                        }
                    }
                }
            }
            return -1;
        }
};

int main(){
    vector<int> vec={1,1,2,3,3,4,4,8,8};
    Solution s;
    cout<<s.singleNonDuplicate(vec)<<endl;
    return 0;
}