#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> vis;
int n,m,ans = 0;

int dfs(vector<vector<int>>& grid, int i, int j){
    if(i<0 || i>=n || j<0 || j>=m || grid[i][j] == 0 || vis[i][j]) return 0;
    vis[i][j] = 1;
    return 1 + dfs(grid, i+1, j) + dfs(grid, i-1, j) + dfs(grid, i, j+1) + dfs(grid, i, j-1);
}
int maxAreaOfIsland(vector<vector<int>>& grid) {
    n = grid.size(), m = grid[0].size();
    vis = vector<vector<int>>(n, vector<int>(m, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j] == 1 && !vis[i][j]){
                ans = max(ans, dfs(grid, i, j));
            }
        }
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> g = {{0,0,1,0,0,0,0,0}};
    cout << maxAreaOfIsland(g);
    return 0;
}