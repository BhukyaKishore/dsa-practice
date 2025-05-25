#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    //to help traverse subArray in O(n^3)
    void TraverseSubArray(vector<int>& nums,int n){
        for(int i=0;i<=n;i++){
            for (int j = i; j <=n; j++)
            {
                for (int k = i; k <j; k++)
                {
                    cout<<nums[k];
                }
                cout<<" ";
            }
            cout<<endl;
        }
    }
    // to find max sum in O(n^3)
    int Maxsum_n3(vector<int>& vec, int n){
        int maxsum=INT32_MIN;
        for (int i = 0; i <=n; i++)
        {
            for (int j = i; j <=n; j++)
            {
                int sum=0;
                for (int k = i; k <n; k++)
                {
                    sum+=vec[k];
                    maxsum=max(sum,maxsum);
                }
                
            }
            
        }
        return maxsum;
    }

    //to find max element in O(n^2)
    int maxsum_n2(vector<int>& nums,int n){
        int maxSum=INT32_MIN;
        for (int i = 0; i <=n; i++)
        {
            int currentSum=0;
            for (int j = i; j <n; j++)
            {
                currentSum+=nums[j];
                maxSum=max(maxSum,currentSum);
            }
            
        }
        return maxSum;
    }

    //to find the max sum of array in O(n) kadane's algorithm 
    int maxsum_n(vector<int>& vec ,int n){
        int maxsum=INT32_MIN;
        int currentSum=0;
        for(int i=0;i<n;i++){
            currentSum+=vec[i];
            if(currentSum<0){
                currentSum=0;
            }
            maxsum=max(currentSum,maxsum);
        }
        return maxsum;
    }
};

int main(){
    vector<int> vec={3,-4,5,4,-1,7,-8};
    Solution s;
    s.TraverseSubArray(vec,vec.size());
    cout<<s.Maxsum_n3(vec,vec.size())<<endl;
    cout<<s.maxsum_n2(vec,vec.size())<<endl;
    cout<<s.maxsum_n(vec,vec.size())<<endl;
    return 0;
}