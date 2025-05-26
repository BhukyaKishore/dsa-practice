#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int maxArea(vector<int>& height) {
            int start=0,end=height.size()-1,currentvolume=0,maxvolume=0,minheight=0;
            while(start<end){
                minheight=min(height[start],height[end]);
                currentvolume=minheight*(end-start);
                maxvolume=max(currentvolume,maxvolume);
                if(height[start]<height[end]){
                    start++;
                }else{
                    end--;
                }
            }
            return maxvolume;
        }
    };
int main(){
    Solution s;
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout<<s.maxArea(height)<<endl;
    return 0;
}