#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int peakIndexInMountainArray(vector<int>& arr) {
            int l = 0, r = arr.size() - 1, mid;
            while (l < r) {
                mid = (l + r) / 2;
                cout<<arr[mid]<<endl;
                if (arr[mid] < arr[mid + 1])
                    l = mid + 1;
                else
                    r = mid;
            }
            return l;
        }
        int mysolution(vector<int>& nums) {
            int st=1,end=nums.size()-2;
            while(st<=end){
                int mid=st+(end-st)/2;
                if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
                    return mid;
                }else{
                    if(nums[mid]<nums[mid+1]){
                        st=mid+1;
                    }else{
                        end=mid-1;
                    }
                }
            }
            return -1;
        }
}s;

int main(){
    vector<int> vec={0,10,5,2};
    cout<<s.mysolution(vec)<<endl;    
    return 0;
}