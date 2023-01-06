#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define INF 1e9


const int mxN = 1e6+20;
ll n, k;
ll ar[mxN], dp[mxN];

int main() {
    cin >> n >> k;
    for(int i=0; i<n; i++) {
        ll a, b; cin >> a >> b;
        ar[b] = a;
    }

    dp[0] = ar[0];
    for(int i=1; i<=1000000; i++) {
        dp[i] = dp[i-1] + ar[i];
    }

    ll ans = 0;
    if(k >= 1000000) ans = dp[1000000];
    else {
        for(int i=0; i<=1000000; i++) {
            if(i+k > 1000000 || i - k < 0) continue;
            ans = max(ans, dp[i+k] - dp[i-k-1]);
        }
    }

    cout << ans;
} 
