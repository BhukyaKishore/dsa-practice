#include<iostream>
#include<vector>
#include<set>
using namespace std;
int main() {
    set<vector<int>> s={{1,2,2},{2,2,1},{2,2,1}};
    for(vector<int> val:s){
        cout<<val[0]<<" "<<val[1]<<" "<<val[2]<<endl;
    }
    return 0;
}