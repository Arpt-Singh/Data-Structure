#include<bits/stdc++.h>
using namespace std;

void reverseArray(vector<int>&arr,int n){
    int left = 0;
    int right = n-1;
    while(left<right){
        swap(arr[left],arr[right]);
        left+=1;
        right-=1;
    }
}
int main(){
    vector<int>arr = {1,2,3,4,5};
    int n = arr.size();
    reverseArray(arr,n);
    for(auto ele:arr){
        cout<<ele<<" ";
    }
    return 0;
}
