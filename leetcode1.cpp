#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector <int> ans;
        sort(nums.begin(),nums.end());
        int i=0,j=nums.size()-1;
        while(i<=j){
            if(nums[i]+nums[j]>target){
                j--;
            }
            else if(nums[i]+nums[j]<target){
                i++;
            }else if(nums[i]+nums[j]==target){
                ans.push_back(i);
                ans.push_back(j);
                return ans ;
            }
        }
        return ans;
    }
};

int main() {
    int n, target;
    cin >> n; // Number of elements

    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    cin >> target;

    Solution sol;
    vector<int> result = sol.twoSum(nums, target);
    for (int idx : result) cout << idx << " ";
    cout << endl;

    return 0;
}
