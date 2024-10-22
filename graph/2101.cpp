#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> flag;
int dfs(vector<vector<int>>& bombs, int x){
    flag[x] = 1;
    int cnt = 0;
    for(auto y: g[x]){
        if(flag[y] == 0) cnt += dfs(bombs, y) + 1;
    }
    return cnt;
}
int maximumDetonation(vector<vector<int>>& bombs) {
    int n = bombs.size();
    g = vector<vector<int>>(n);
    
    // build graph g[i] contain the target that can be detonated by bomb i
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int x1 = bombs[i][0], y1 = bombs[i][1], r1 = bombs[i][2];
            int x2 = bombs[j][0], y2 = bombs[j][1];
            if(pow((x2-x1), 2) + pow((y2-y1), 2) <= pow(r1,2)) g[i].push_back(j);
        }
    }
    
    int ans = 0;
    for(int i=0; i<bombs.size(); i++){
        flag = vector<int>(n, 0);
        ans = max(ans, 1 + dfs(bombs, i));
    }
    return ans;
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> v = {{2,1,3},{6,1,4}};
    cout<<maximumDetonation(v)<<endl;

    return 0;
}