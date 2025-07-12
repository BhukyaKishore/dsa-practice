// You are climbing a staircase. It takes n steps to reach the top.

// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

// Example 1:

// Input: n = 2
// Output: 2
// Explanation: There are two ways to climb to the top.
// 1. 1 step + 1 step
// 2. 2 steps
// Example 2:

// Input: n = 3
// Output: 3
// Explanation: There are three ways to climb to the top.
// 1. 1 step + 1 step + 1 step
// 2. 1 step + 2 steps
// 3. 2 steps + 1 step

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        vector<int> ans(n+1,0);
        for(int i=0;i<ans.size();i++){
            if(i==0 || i==1 || i==2){
                ans[i]=i;
            }else{
                ans[i]=ans[i-1]+ans[i-2];
            }
        }
        return ans[n];
    }
}s;

int main(){
    cout<<s.climbStairs(3)<<endl;
    return 0;
}