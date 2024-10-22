// 二分查找 + 前缀优化


#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;

int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
    int n = profit.size();
    vector<pair<int,int>> a(n);
    for(int i=0; i<n; i++) { a[i].first = difficulty[i]; a[i].second = profit[i]; }
    sort(a.begin(), a.end());

    vector<int> max_profit(n, 0);       // max_profit[i] 表示 0~i 之间 profit[i] 的最大值
    max_profit[0] = a[0].second;
    for(int i=1; i<n; i++){ max_profit[i] = max(a[i].second, max_profit[i-1]); }

    ll ans = 0;
    for(auto d: worker){
        int l=0, r=n-1;
        while(l<r){                     // 二分查找可行 difficulty 的 upper_bound
            int mid = (l+r+1)/2;
            if(a[mid].first <= d) l = mid;
            else r = mid-1;
        }
        if(d >= a[l].first) ans += max_profit[l];       // 二分完了之后还需要检查一下
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> a = {85,47,57}, b = {24,66,99}, c = {40,25,25};
    cout<<maxProfitAssignment(a,b,c)<<endl;
    return 0;
}