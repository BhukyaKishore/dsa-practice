// You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

// You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [[7,4,1],[8,5,2],[9,6,3]]

// Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
// Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& m) {
        for(int i=0;i<m.size();i++){
            for(int j=i+1;j<m.size();j++){
                int temp=m[i][j];
                m[i][j]=m[j][i];
                m[j][i]=temp;
            }
        }
        for(int i=0;i<m.size();i++){
            for(int j=0;j<m.size()/2;j++){
                int temp=m[i][j];
                m[i][j]=m[i][m.size()-1-j];
                m[i][m.size()-1-j]=temp;
            }
        }
    }
}s;

int main(){
    vector<vector<int>> vec={{1,2,3},{4,5,6},{7,8,9}};
    s.rotate(vec);
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec.size(); j++)
        {
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }
    

    
    return 0;
}