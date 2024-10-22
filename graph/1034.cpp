#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> vis;
int n,m,c,b_color;
int dfs(vector<vector<int>>& grid, int i, int j){
    if(i<0 || i>=n || j<0 || j>=m || grid[i][j] != c) return 1;
    if(vis[i][j] == 1) return 0;
    vis[i][j] = 1;
    // must dfs to all 4 directions
    int cnt = dfs(grid, i+1, j) + dfs(grid, i-1, j) + dfs(grid, i, j+1) + dfs(grid, i, j-1);
    if(cnt > 0) vis[i][j] = -1;     // didn't change grid directly
    return 0;
}

vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
    n = grid.size(), m = grid[0].size(), c = grid[row][col], b_color = color;
    vis = vector<vector<int>>(n, vector<int>(m, 0));
    dfs(grid, row, col);
    for(int i=0; i<n; i++){         // avoid the changing grid affect the detection
        for(int j=0; j<m; j++){
            if(vis[i][j] == -1) grid[i][j] = b_color;
        }
    }
    return grid;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> g = {{1,1,1},{1,1,1},{1,1,1}};
    colorBorder(g, 1, 1, 2);
    for(auto i: g){
        for(auto j: i) cout << j << " ";
        cout << "\n";
    }

    return 0;
}