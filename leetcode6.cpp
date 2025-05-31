/*The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);

Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I
Example 3:

Input: s = "A", numRows = 1
Output: "A"

Constraints:

1 <= s.length <= 1000
s consists of English letters (lower-case and upper-case), ',' and '.'.
1 <= numRows <= 1000*/
#include<iostream>
#include<string>
using namespace std;
class Solution {
    public:
        string convert(string s, int numRows) {
            int i=0,st=0;
            string word="";
            char c;
            if(numRows==1) return s;
            while(word.size()!=s.size()){
                if(i>s.size()-1){
                    i=++st;
                }
                c=(char)s[i];
                // cout<<i<<endl;
                word.push_back(c);
                i=i+numRows+1;
            }
            word+=s[i];
            return word;
        }
}s;
int main(){
    string word = "PAYPALISHIRING";
    int numRows = 3;
    cout<<"PAHNAPLSIIGYIR"<<endl;
    cout<<word.size()<<" "<<word[13]<<endl;
    cout<<s.convert(word,numRows)<<endl;
    return 0;
}