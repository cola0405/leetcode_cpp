#include <bits/stdc++.h>
using namespace std;


vector<vector<int>> ans;
int dst;

void dfs(int cur, vector<int> path, vector<vector<int>>& graph){
    if(find(path.begin(), path.end(), cur) != path.end()) return;
    path.push_back(cur);
    if(cur == dst) {
        ans.push_back(path);
        return;
    }
    for(auto x: graph[cur]){
        dfs(x, path, graph);
    }
}
vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    dst = graph.size()-1;
    dfs(0, {}, graph);
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    return 0;
}