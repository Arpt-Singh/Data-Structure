#include <bits/stdc++.h>
using namespace std;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

void dfs(vector<vector<char>>&grid,int i,int j){
    if(i<0 or j<0 or i>=grid.size() or j>=grid[0].size() or grid[i][j]!='1') return;

    grid[i][j] = '2';
    for(int k=0;k<4;k++){
        int new_i = i+dx[k], new_j = j+dy[k];
        dfs(grid,new_i,new_j);
    }
}

int main() {
    vector<vector<char>> grid = { { '1', '1', '0', '0', '0' },
                              { '0', '1', '0', '0', '1' },
                              { '1', '0', '0', '1', '1' },
                              { '0', '0', '0', '0', '0' },
                              { '1', '0', '1', '1', '0' } };

    int r = grid.size();
    int c = grid[0].size();
    int count = 0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(grid[i][j]=='1'){
                dfs(grid,i,j);
                count++;
            }

        }
    }
    cout<<count<<endl;
    return 0;
}

