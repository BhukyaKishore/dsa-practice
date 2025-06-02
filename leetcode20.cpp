#include <iostream>
#include <stack>
using namespace std;
class Solution {
    public:
        bool isValid(string s) {
            char st=s[0],end=s[s.size()-1];
            if(st==')'||st=='}'||st==']' ||end=='{'||end=='['||end=='(') return false;
            stack<char> stk;
            for(int i=0;i<s.size();i++){
                if(stk.empty()){
                    stk.push(s[i]);
                }else if((s[i]==')' && stk.top()=='(')||(s[i]==']' && stk.top()=='[')||(s[i]=='}' && stk.top()=='{')){
                    stk.pop();
                }else{
                    stk.push(s[i]);
                }
            }
            return (stk.empty())?true:false;
        }
}s;

int main(){
    string st="()[]{}";
    cout<<s.isValid(st);    
    return 0;
}