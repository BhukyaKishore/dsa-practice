/*2259. Remove Digit From Number to Maximize Result
Easy
Topics
premium lock icon
Companies
Hint
You are given a string number representing a positive integer and a character digit.

Return the resulting string after removing exactly one occurrence of digit from number such that the value of the resulting string in decimal form is maximized. The test cases are generated such that digit occurs at least once in number.

Example 1:

Input: number = "123", digit = "3"
Output: "12"
Explanation: There is only one '3' in "123". After removing '3', the result is "12".
Example 2:

Input: number = "1231", digit = "1"
Output: "231"
Explanation: We can remove the first '1' to get "231" or remove the second '1' to get "123".
Since 231 > 123, we return "231".
Example 3:

Input: number = "551", digit = "5"
Output: "51"
Explanation: We can remove either the first or second '5' from "551".
Both result in the string "51".

Constraints:

2 <= number.length <= 100
number consists of digits from '1' to '9'.
digit is a digit from '1' to '9'.
digit occurs at least once in number.*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;
// i firstly tryto slove it with wrong approch like removing all d's one by one and compare every ans and 
// try to return large ans but thay give the n such it does not fit in long long too so i changed my approch and 
// slove this problem in this way....
class Solution {
    public:
        string removeDigit(string n, char d) {
            int lastoccurance=0,count=0;
            for (int i = 1; i < n.size()+1; i++)
            {
                if((char)n[i-1]==d){
                    count++;
                    lastoccurance=i-1;
                    if((int)(char)n[i]>(int)(char)n[i-1] && i<n.size()){
                        n.erase(i-1,1);
                        return n;
                    }
                }
            }
            if(count>0){
            n.erase(lastoccurance,1);
            return n;
            }
            return n;
        }
        //another approch 
        //it remove every occurance and compare it by default string comparision follow Lexicographical (Distnory order) so it works and 
        // store the soln in maxresult...
        string approch2(string number, char digit) {
            string maxResult = "";
            for (int i = 0; i < number.length(); ++i) {
                if (number[i] == digit) {
                    string temp = number.substr(0, i) + number.substr(i + 1);
                    if (temp > maxResult) {
                        maxResult = temp;
                    }
                }
            }
            return maxResult;
        }

}s;

int main(){
    string n="2998589353917872714814599237991174513476623756395992135212546127959342974628712329595771672911914471";
    char d='3';
    cout<<s.removeDigit(n,d)<<endl;
    n="2121";
    d='1';
    cout<<s.removeDigit(n,d)<<endl;
    return 0;
}

