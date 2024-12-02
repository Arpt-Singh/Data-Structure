#include<bits/stdc++.h>
using namespace std;
void moveallzerotoend(vector<int>&arr,int n){
    int count =0;
    for(int i=0;i<n;i++){
        if(arr[i]!=0){
            swap(arr[i],arr[count]);
            count++;
        }
    }
}

int main(){
    vector<int> arr = {1,2,0,4,3,0,5,0};
    moveallzerotoend(arr,arr.size());
    for(auto element:arr){
        cout<<element<<" ";
    }
    return 0;
}