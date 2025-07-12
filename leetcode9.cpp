// Given an integer x, return true if x is a palindrome, and false otherwise.

// Example 1:

// Input: x = 121
// Output: true
// Explanation: 121 reads as 121 from left to right and from right to left.
// Example 2:

// Input: x = -121
// Output: false
// Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
// Example 3:

// Input: x = 10
// Output: false
// Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int num) {
        if (num< 0) return false;
        unsigned int sum=0,rem=0;
        int temp=num;
        while(num>0){
            rem=num%10;
            sum=sum*10+rem;
            num/=10;

        }
        if(sum==temp){
            return true;
        }
        return false;
    }
}s;

int main(){
    cout<<s.isPalindrome(121)<<endl;
    cout<<s.isPalindrome(-121)<<endl;
    return 0;
}