/*
    default output format will not show all digit after decimal point, but it do exist
    the reason "float" fail is that it's not accurate enough

    float a = 499999999;
    double b = 499999999;
    cout<< fixed << setprecision(20) << 1000000000/a<<endl;
    cout<< fixed << setprecision(20) << 1000000000/b<<endl;
    cout<<ceil(1000000000/a)<<endl;
    cout<<ceil(1000000000/b)<<endl;

 */

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool ok(double k, int h, const vector<int>& p){     // float can't AC
    long long need = 0;
    for(auto x: p){
        need += ceil(x/k);
        if(need > h) return false;
    }
    return true;
}
int minEatingSpeed(const vector<int>& piles, int h) {
    int l=1, r=1e9;
    while(l < r){
        int mid = (l+r)/2;
        if(ok(mid, h, piles)) r = mid;
        else l = mid+1;
    }
    return l;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout<< minEatingSpeed({1000000000}, 2)<<endl;
    return 0;
}