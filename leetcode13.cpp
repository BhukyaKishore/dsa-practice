#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
        int valchange(char c){
            if(c=='I') return 1;
            if(c=='V') return 5;
            if(c=='X') return 10;
            if(c=='L') return 50;
            if(c=='C') return 100;
            if(c=='D') return 500;
            if(c=='M') return 1000;
            return 0;
        }
        //first i tried from starrting but it give wrong answer in "MCMXCIV" case so i decide to do it from backside 
        // using same logic actually it works :)
        int romanToInt(string s) {
            
            int val=valchange(s[s.size()-1]);
            for(int i=s.size()-2;i>=0;i--){
                if(valchange(s[i+1])<=valchange(s[i])){
                    val+=valchange(s[i]);
                }else{
                    val-=valchange(s[i]);
                }
            }
            return val;
        }
}v;

int main(){
    // vector<int> vec={1,-2,2,3,5,8};
    Solution v;
    string s="MCMXCIV";//1994
    cout<<v.romanToInt(s)<<endl;
    return 0;
}