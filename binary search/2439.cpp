#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
bool ok(vector<int> nums, int k){
    int n=nums.size();
    vector<ll> a(n);
    for(int i=0; i<n; i++) a[i] = ll(nums[i]);
    for(int i=n-1; i>0; i--){       // 从右往左
        if(a[i] > k){
            a[i-1] += a[i]-k;
            a[i] = k;
        }
    }    return a[0] <= k;
}

int minimizeArrayValue(vector<int>& nums) {
    int l=nums[0], r=*max_element(nums.begin(), nums.end());
    while(l<r){
        int mid = (l+r)/2;
        if(ok(nums, mid)) r = mid;
        else l = mid+1;
    }
    return l;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> a = {3,7,1,6};
    cout<<minimizeArrayValue(a)<<endl;
    return 0;
}