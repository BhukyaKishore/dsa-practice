#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int>& nums,int st,int mid,int end){
    int n1=mid-st+1;
    int n2=end-mid;
    vector<int> arr1(n1,0);
    vector<int> arr2(n2,0);
    for (int i = 0; i < n1; i++)
    {
        arr1[i]=nums[st+i];
    }
    for (int i = 0; i < n2; i++)
    {
        arr2[i]=nums[mid+i+1];
    }
    int i=0,j=0,k=st;
    while(i<n1 && j<n2){
        if(arr1[i]<arr2[j]) nums[k++]=arr1[i++];
        else nums[k++]=arr2[j++];
    }
    while(i<n1){
        nums[k++]=arr1[i++];
    }
    while(j<n2){
        nums[k++]=arr2[j++];
    }
}
void mergeSort(vector<int>& nums,int st,int end){
    if (st >= end) return;
    int mid=(st+end)/2;
    mergeSort(nums,st,mid);
    mergeSort(nums,mid+1,end);
    merge(nums,st,mid,end);

}
int main(){
    vector<int> s={8,7,3,9,4,64,3,35,1,12};
    mergeSort(s,0,s.size()-1);
    for(auto val:s){
        cout<<val<<" ";
    }
    return 0;
} 