#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int Singlenumber(vector<int> nums){
        int n=0;
        for(int val:nums){
            n^=val;
        }
        return n;
    }
};

int main(){
    Solution s;
    vector<int> vec;
    vec={1,1,2,5,2};
    cout<<s.Singlenumber(vec)<<endl;
    vec={1};
    cout<<s.Singlenumber(vec)<<endl;
    vec={4,1,5,2,5,1,2};
    cout<<s.Singlenumber(vec)<<endl;
    return 0;
}