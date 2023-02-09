#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1e9

const int mxN = 2e5+10, mxK = 2e9+10;
int n, k;
ll ar[mxN], dp[mxN];
map<ll, ll> mp;

int main () {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    for(int i=0; i<n; i++) {
        cin >> ar[i];
        if(i == 0) dp[i] = ar[i];
        else {
            dp[i] = dp[i-1] + ar[i];
        }
    }
    
    ll ans = 0;
    for(int i=0; i<n; i++) {
        if(dp[i] == k) ans++;

        ans += mp[dp[i] - k];
        mp[dp[i]]++;
    }

    cout << ans;
}