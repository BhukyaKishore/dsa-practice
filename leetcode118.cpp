#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        vector<vector<int>> generate(int n) {
            vector<vector<int>> ans;
            for (int i = 0; i < n; i++) {
                vector<int> row(i + 1, 1);//intilizing all elements with 1 
                for (int j = 1; j < i; j++) {
                    row[j] = ans[i - 1][j - 1] + ans[i - 1][j]; //calculating middle element with outher element for previous values of nums
                }
                ans.push_back(row);
            }
            return ans;
        }
    };

int main(){
    //code to draw passcal tryng
    int n=15;
    Solution s;
    vector<vector<int>> ans=s.generate(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i+1; j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    
    
    return 0;
}