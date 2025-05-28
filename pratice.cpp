#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;

int main(){
    vector<int> nums={9,5,7,8,7,9,8,2,0,7};
    nums.erase(nums.begin()+2);
    int j = 0;  // write index
    for (int i = 0; i < nums.size(); ++i) {
        if (j < 2 || nums[i] != nums[j - 2]) {
            nums[j++] = nums[i];
        }
    }
    return j;

    // int i=0,j=nums.size()-1;
    // set<int> elements;
    // sort(nums.begin(),nums.end());
    // while(i<j){
    //     elements.insert((nums[i++]+nums[j--])/2);
    // }
    // cout<<endl;

//80
// class Solution {
//     public:
//         int removeDuplicates(vector<int>& nums) {
//             int j = 0;  // write index
//             for (int i = 0; i < nums.size(); ++i) {
//                 if (j < 2 || nums[i] != nums[j - 2]) {
//                     nums[j++] = nums[i];
//                 }
//             }
//             return j;
//         }
//     };
}