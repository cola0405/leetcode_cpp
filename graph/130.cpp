#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> vis;
int n,m,mark = 1;

// dfs check current area is surrounded or not
bool dfs(vector<vector<char>>& board, int i, int j){
    if(i<0 || i>=n || j<0 || j>=m) return false;
    if(board[i][j] == 'X' || vis[i][j] == mark) return true;
    vis[i][j] = mark;
    return dfs(board, i-1, j) && dfs(board, i+1, j) && dfs(board, i, j-1) && dfs(board, i, j+1);
}

// update current area after check out the board
void change(vector<vector<char>>& board, int i, int j){
    if(i<0 || i>=n || j<0 || j>=m || board[i][j] == 'X' || vis[i][j] != mark) return;
    vis[i][j] = -1;
    board[i][j] = 'X';
    change(board, i-1, j);
    change(board, i+1, j);
    change(board, i, j-1);
    change(board, i, j+1);
}
void solve(vector<vector<char>>& board) {
    n = board.size(), m = board[0].size();
    vis = vector<vector<int>>(n, vector<int>(m, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(board[i][j] == 'O' && vis[i][j] == 0 && dfs(board, i, j)) {
                change(board, i, j);
            }
            mark++;     // we should change the mark every turn
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<vector<char>> v = {{'O','O','O','O','X','X'},
                              {'O','O','O','O','O','O'},
                              {'O','X','O','X','O','O'},
                              {'O','X','O','O','X','O'},
                              {'O','X','O','X','O','O'},
                              {'O','X','O','O','O','O'}};
    solve(v);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    

    return 0;
}