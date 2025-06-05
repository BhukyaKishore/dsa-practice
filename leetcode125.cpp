#include<iostream>
#include<string>
using namespace std;
class Solution {
    public:
        bool isPalindrome(string s) {
            int st=0,end=s.size()-1,stchar,endchar;
            while(st<=end){
                stchar=tolower(s[st]);
                endchar=tolower(s[end]);
                if((stchar<97 || stchar>122) && !(stchar>=47 && stchar<=57)){ st++;}
                else if((endchar<97 || endchar>122) && !(endchar>=47 && endchar<=57)){ end--;}
                else{
                    if(stchar==endchar){
                        st++;
                        end--;
                    }else{
                        return false;
                    }
                }
            }
            return true;
        }
    }sol;

int main(){
    //i made so many silly maistake while sloving this problem :)
    /*Input: s = "A man, a plan, a canal: Panama"
    Output: true
    Explanation: "amanaplanacanalpanama" is a palindrome.*/
    string s = "A man, a plan, a canal: Panama";
    cout<<sol.isPalindrome(s)<<endl;
    s = "1b21";
    cout<<sol.isPalindrome(s)<<endl;
}