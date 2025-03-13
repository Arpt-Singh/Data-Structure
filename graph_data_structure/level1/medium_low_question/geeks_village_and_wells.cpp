#include <bits/stdc++.h>
using namespace std;

/* multi source BFS*/


vector<vector<int>> solver(int n,int m,vector<vector<char>>&grid){
    vector<vector<int>> direction = {{0,1},{1,0},{-1,0},{0,-1}};
    vector<vector<int>> res(n,vector<int>(m,0));
    queue<pair<int,int>>q;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='W'){
                q.push({i,j});
            }
        }
    }
    int count = 1;
    while(!q.empty()){
        int size = q.size();
        while(size--) {
            pair<int,int> p = q.front();
            q.pop();
            int row = p.first, col = p.second;
            for(auto &dir: direction){
                int new_row = row + dir[0];
                int new_col = col + dir[1];

                if(new_row >= 0 && new_col >=0 && new_row<n && new_col<m && (grid[new_row][new_col] == 'H' || grid[new_row][new_col] == '.')) {
                    if(grid[new_row][new_col] == 'H') {
                        res[new_row][new_col] = 2 * count;
                    }
                    grid[new_row][new_col] = 'X';
                    q.push({new_row,new_col});
                }
            }
        }
        count++;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] == 'H'){
                res[i][j] = -1;
            }
        }
    }
    return res;

}

int main() {
    vector<vector<char>> grid = {{'H','H','H'},{'H','W','H'},{'H','H','H'}};
    /*Output should be:
    4 2 4
    2 0 2
    4 2 4
    */
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> ans = solver(n,m,grid);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}