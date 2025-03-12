#include<bits/stdc++.h>
#include<queue>
using namespace std;


int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};


int rottening_oranges(vector<vector<int>>&grid) {
    int r = grid.size(), c = grid[0].size();
    int ans = 0;
    queue<pair<int,int>>q;
    for(int i=0;i<r;i++){
        for(int j = 0;j<c;j++){
            if(grid[i][j]==2){
                q.push({i,j});
            }
        }
    }
    while(!q.empty()){
        int sz = q.size();
        int temp = 0;
        while(sz--){
            auto p = q.front();
            q.pop();
            for(int k=0;k<4;k++){
                int i = p.first + dx[k];
                int j = p.second + dy[k];
                if(i>=0 and j>=0 and i<r and j<c and grid[i][j]==1){
                    grid[i][j]=2;
                    temp = 1;
                    q.push({i,j});

                }
            }
        }
        ans += temp;
    }
    for(auto v:grid){
        for(auto x:v){
            if(x==1) return -1;
        }
    }
    return ans;


}
int main(){

    vector<vector<int>> grid = {{ 2,1,1 }, { 1, 1, 0 }, { 0, 1, 1 }}; // input
    //output should be : 4
    int ans = rottening_oranges(grid);
    cout<<ans<<endl;
    
    return 0;

}