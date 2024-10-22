// 用Map构造graph会超时

#include <bits/stdc++.h>
using namespace std;


vector<int> vis;
vector<vector<int>> g;

bool dfs(int x, int destination){
    vis[x] = 1;
    if(x == destination) return true;
    for(auto &v: g[x]){
        if(!vis[v] && dfs(v, destination)) return true;
    }
    return false;
}
bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
    g = vector<vector<int>>(n);
    vis = vector<int>(n+1, 0);
    for(auto v: edges){
        int a = v[0], b = v[1];
        g[a].push_back(b);
        g[b].push_back(a);
    }
    return dfs(source, destination);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> vv = {{0,1}, {0,2}, {3,5}, {5,4}, {4,3}};
    cout<<validPath(6,vv, 0,5)<<endl;

    return 0;
}