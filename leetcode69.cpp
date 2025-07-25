// Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

// You must not use any built-in exponent function or operator.

// For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.

// Example 1:

// Input: x = 4
// Output: 2
// Explanation: The square root of 4 is 2, so we return 2.
// Example 2:

// Input: x = 8
// Output: 2
// Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.

#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if(x==0) return 0;
        if(x==1) return 1;
        unsigned int st=1,end=x,mid=0;
        while(st<=end){
            mid=(st+end)/2;
            if(pow(mid,2)<=x && pow(mid+1,2) >x){
                return mid;
            }else if(pow(mid,2)>x){
                end=mid-1;
            }else{
                st=mid+1;
            }
        }
        return -1;
    }
}s;

int main(){
    cout<<s.mySqrt(10)<<endl;
    return 0;
}