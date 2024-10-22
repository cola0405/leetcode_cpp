// two pointer + greedy
// we only do the necessary operations
#include <bits/stdc++.h>
using namespace std;

long long minimumSteps(string s) {
    int i=0, n = s.size();
    long long ans = 0;
    for(int j=0; j<n; j++){
        if(s[j] == '0'){
            ans += j-i;
            i++;
        }
    }
    return ans;
}

int main() {
    cout<<minimumSteps("100")<<endl;
    return 0;
}