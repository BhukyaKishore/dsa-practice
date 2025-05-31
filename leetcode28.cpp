/*Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.
Example 2:

Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.

Constraints:

1 <= haystack.length, needle.length <= 104
haystack and needle consist of only lowercase English characters.*/
#include<iostream>
#include<string>
using namespace std;
class Solution {
    public:
        int strStr(string haystack, string needle) {
            int n=needle.size(),j=0,i,back,count=0;
            for( i=0;i<haystack.size() && j<needle.size();i++){
                if(n==0)return (i-needle.size());
                if (haystack[i]==needle[j]){
                    if(haystack[i]==needle[0] && j>0 && count==0 && i>0){
                        back=i;
                        count++;
                    }
                    n--;
                    j++;
                }else{
                    j=0;
                    n=needle.size();
                    if(count>0){
                    count=0;
                    i=back;
                    }
                    if (haystack[i]==needle[j]){
                    n--;
                    j++;
                    }
                }
            }
            return (n==0)?(i-needle.size()):-1;
        }

        //another approch
        //this guy use the builtin substring approch but i write it for my own
        //konwing priviously avalible approches also important :)
        int strStr(std::string haystack, std::string needle) {
            for (int i = 0; i <= haystack.length() - needle.length(); ++i) {
                if (haystack.substr(i, needle.length()) == needle) {
                    return i;
                }
            }
            return -1;
        }
}s;


//i made some mistake in this but i learn that edge cases are importand backtracking the problem in paper to understand better and logic
//have to be prefact dont deive into the problem statement directly first understande the question slove it on paper and backtrack and write 
//some tast cases and identify edge cases and make it simple and fast
// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/solutions/6750826/video-slicing-approach
// easy approch
int main(){
    string haystack="mississippi";
    string needle="issip";
    cout<<s.strStr(haystack,needle)<<endl;
    haystack="babba";
    needle="bbb";
    cout<<s.strStr(haystack,needle)<<endl;

}