// You are given an array of characters letters that is sorted in non-decreasing order, and a character target. There are at least two different characters in letters.

// Return the smallest character in letters that is lexicographically greater than target. If such a character does not exist, return the first character in letters.

// Example 1:

// Input: letters = ["c","f","j"], target = "a"
// Output: "c"
// Explanation: The smallest character that is lexicographically greater than 'a' in letters is 'c'.
// Example 2:

// Input: letters = ["c","f","j"], target = "c"
// Output: "f"
// Explanation: The smallest character that is lexicographically greater than 'c' in letters is 'f'.
// Example 3:

// Input: letters = ["x","x","y","y"], target = "z"
// Output: "x"
// Explanation: There are no characters in letters that is lexicographically greater than 'z' so we return letters[0].

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& nums, char target) {
        if(nums[nums.size()-1]<=target) return nums[0];
        if(nums[0]>target) return nums[0];
        int st=0,end=nums.size()-2,mid=0;
        while(st<=end){
            mid=st+(end-st)/2;
            if(nums[mid+1]>target && nums[mid]<=target){
                return nums[mid+1];
            }else if(nums[mid]<=target){
                st=mid+1;
            }else{
                end=mid-1;
            }
        }
        return nums[0];
    }
}s;

int main(){
    vector<char> vec= {'c','f','j'};
    cout<<s.nextGreatestLetter(vec,'f')<<endl;
    return 0;
}