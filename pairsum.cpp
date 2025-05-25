#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
    //bruteforce way to find all possible pair sum and compare with target and returning solution
    vector<int> pairsum_bruteforce(vector<int>& nums,int target){
        vector<int> sol;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i+1; j < nums.size(); j++)
            {
                if(nums[i]+nums[j]==target){
                    sol.push_back(i);
                    sol.push_back(j);
                    return sol;
                }
            }
            
        }
        return sol;
    }

    //optimize way to find that pair in a sored arr 
    vector<int> pairsumopt(vector<int>& nums ,int target){
        //there exist at leat one pair to satisfy that condition so 
        int i=0,j=nums.size()-1;
        vector<int> sol;
        while(nums[i]+nums[j]!=target){
            if (nums[i]+nums[j]<target)
            {
                i++;
            }
            else if (nums[i]+nums[j]>target)
            {
                j--;
            }
        }
        if(nums[i]+nums[j]==target){
            sol.push_back(i);
            sol.push_back(j);
        }
        return sol;
    }

};

int main(){
    Solution s;
    vector<int> nums;
    nums={-1,2,3,4,5,10};
    vector<int> sol;
    sol=s.pairsum_bruteforce(nums,7);
    cout<<sol[0]<<" "<<sol[1]<<endl;
    sol=s.pairsum_bruteforce(nums,12);
    cout<<sol[0]<<" "<<sol[1]<<endl;
    sol=s.pairsum_bruteforce(nums,9);
    cout<<sol[0]<<" "<<sol[1]<<endl;
    sol=s.pairsumopt(nums,7);
    cout<<sol[0]<<" "<<sol[1]<<endl;
    sol=s.pairsumopt(nums,12);
    cout<<sol[0]<<" "<<sol[1]<<endl;
    sol=s.pairsumopt(nums,9);
    cout<<sol[0]<<" "<<sol[1]<<endl;
    return 0;
}