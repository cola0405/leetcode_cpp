#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> g;
vector<int> vis;

void dfs(vector<vector<int>>& isConnected, int x){
    vis[x] = 1;
    for(int next=0; next<n; next++){
        if(!vis[next] && isConnected[x][next]) dfs(isConnected, next);
    }
}
int findCircleNum(vector<vector<int>>& isConnected) {
    n = isConnected.size();
    vis = vector<int>(n+1, 0);
    int ans = 0;
    for(int i=0; i<n; i++){
        if(!vis[i]){ ans++; dfs(isConnected, i); }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> vv = {{1,1,0},{1,1,0},{0,0,1}};
    cout<<findCircleNum(vv)<<endl;

    return 0;
}