#include <bits/stdc++.h>
using namespace std;
class Solution {
    void dfs(int i, int j, vector<vector<char>> &grid, vector<vector<int>> &visited){
        int m=grid.size();
        int n=grid[0].size();
        visited[i][j]=1;
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        for(int k=0; k<4; k++){
            int nrow=i+drow[k];
            int ncol=j+dcol[k];
            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && grid[nrow][ncol]=='1' && !visited[nrow][ncol]){
                dfs(nrow, ncol, grid, visited);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> visited(m, vector<int> (n,0));
        int ans=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    dfs(i,j,grid,visited);
                    ans++;
                }
            }
        }
        return ans;
    }
};