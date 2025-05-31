/*Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters if it is non-empty.
*/
#include <iostream>
#include <vector>
#include<string>
using namespace std;

class Solution {
    public:
        string longestCommonPrefix(vector<string>& str) {
            string finalans=str[0],presentans="";
            for(int i=1;i<str.size();i++){
                for (int j=0;j<min(str[i].size(),str[i-1].size());j++){
                    if(str[i][j]==str[i-1][j]){
                        presentans.push_back(str[i][j]);
                    }else{
                        break;
                    }
                }
                if(finalans.size()>presentans.size()){
                    finalans=presentans;
                }
                presentans="";
                if(finalans.size()==0){
                    return "";
                }
            }
            return finalans;
    }
    //another approch somewat betterthen privios one 
    string anotherapproch(vector<string>& strs) {
        int n = strs.size();
        if(strs.empty()) return "";
        string pre = strs[0];
        for( string s:strs){
            while(s.find(pre)!=0){
                pre = pre.substr(0,pre.size()-1);// shrink pre
            }
        }
        return pre;
    }
}s;


//editorial link many cases disscused there https://leetcode.com/problems/longest-common-prefix/editorial
int main(){
    vector<string> strs = {"flower","flow","flight"};
    cout<<s.longestCommonPrefix(strs)<<endl;
    cout<<s.anotherapproch(strs)<<endl;
    return 0;
}