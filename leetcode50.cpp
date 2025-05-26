#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    double myPow(double x, int n) {
        //you can also write some edge cases to make excuton some faster like n=0,1,-1 and x=0 etc values
        //it take time complexcity of O(logn)
        long bin=n;
        double ans=1;
        if(n<0){
            x=(1/x);
            bin=-bin;
        }
        while(bin>0){
            if(bin%2==1){
                ans*=x;
            }
            x*=x;
            bin/=2;
        }
        return ans;
    }
    
};
int main(){
    Solution s;
    double x=2.01;
    int n=10;
    cout<<s.myPow(x,n)<<endl;
    return 0;
}