//given an array nums and of size n
//there always exist a mojority element in that array such that it present more then (n/2) times in that array we have to return that element 

#include<iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    //by sorting array a majority element always prent in the middle of that array
    // time  comlexcity O(n^2)
    int majoriyElemrnt_bruteforce(vector<int>& nums){
        for(int val:nums){
            int freq=0;
            for(int i:nums){
                if(val==i){
                    freq++;
                }
            }
            if(freq>(nums.size()/2)){ return val; }
        }
        return -1;
    }
    //finding majority element after sorting that array or
    // just find middle element of that sorted array it always majority element nums[n/2];
    int majoritElemrntSorted(vector<int>& nums){
        int freq=1;
        for(int i=1;i<nums.size();i++){
            if (nums[i]==nums[i-1])
            {
                freq++;
                if(freq>(nums.size()/2)){ return nums[i]; }
            }
            else{
                freq=1;
            }
        }
    }
};

int main(){
    Solution s;
    vector<int> vec;
    // vec={3,1,3,3,3,4,2,2,3};
    // cout<<s.majoriyElemrnt_bruteforce(vec)<<endl;
    vec={1,1,1,2,2};
    cout<<s.majoriyElemrnt_bruteforce(vec)<<endl;
    vec={0,5,5,5,5};
    cout<<s.majoriyElemrnt_bruteforce(vec)<<endl;
    return 0;

}