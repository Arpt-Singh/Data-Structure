#include<bits/stdc++.h>
using namespace std;

int secondLargest(vector<int>&arr,int n){
    int firstMax = INT_MIN;
    int secondMax = INT_MAX;
    for(int i=0;i<n;i++){
        if(arr[i]>firstMax){
            secondMax = firstMax;
            firstMax = arr[i];
        }else if(arr[i]>secondMax && arr[i]!=firstMax){
            secondMax = arr[i];
        }
    }
    if(secondMax!=INT_MIN){
        return secondMax;
    }else{
        return -1;
    }
}
int main(){
    vector<int> arr = {12,35,1,10,34,1};
    int n = arr.size();
    cout<<secondLargest(arr,n);
    return 0;
}