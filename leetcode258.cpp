// Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.

// Example 1:

// Input: num = 38
// Output: 2
// Explanation: The process is
// 38 --> 3 + 8 --> 11
// 11 --> 1 + 1 --> 2 
// Since 2 has only one digit, return it.
// Example 2:

// Input: num = 0
// Output: 0

#include <iostream>
using namespace std;

class Solution {
public:
    int addDigits(int num) {
       if (num==0) return 0;
       int rem=num%9;
       if(rem==0){
        return 9;
       }else{
        return rem;
       }
    }
}s;

int main(){
    cout<<s.addDigits(38)<<endl;    
    return 0;
}