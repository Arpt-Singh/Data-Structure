#include<bits/stdc++.h>
using namespace std;
void reverse(int start,int end,vector<int>&arr){
    while(start<end){
        swap(arr[start],arr[end]);
        start+=1;
        end-=1;
    }

}
void rotateanarray(int n, vector<int>&arr, int k){
    k=k%n;
    reverse(0,k-1,arr);
    reverse(k,n-1,arr);
    reverse(0,n-1,arr);
}
int main(){
    vector<int>arr = {1,2,3,4,5};
    int k = 2;
    int n = arr.size();
    rotateanarray(n,arr,k);
    for(auto ele:arr){
        cout<<ele<<" ";
    }
    return 0;
}