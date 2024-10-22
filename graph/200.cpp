#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int>> vis;
void dfs(vector<vector<char>>& grid, int i, int j){
    if(i<0 || j<0 || i>=n || j>=m || grid[i][j]=='0' || vis[i][j]==1) return;
    vis[i][j] = 1;
    dfs(grid, i+1, j);
    dfs(grid, i-1, j);
    dfs(grid, i, j+1);
    dfs(grid, i, j-1);
}

int numIslands(vector<vector<char>>& grid) {
    n = grid.size();
    m = grid[0].size();
    int ans = 0;
    vis = vector<vector<int>>(n, vector<int>(m, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j]=='1' && vis[i][j] == 0){
                dfs(grid, i,j);
                ans++;
            }
        }
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}