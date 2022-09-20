#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9

const ll MOD = 1e9 + 7;

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    ll dp[n+1];
    dp[2] = 1, dp[4] = 3;
    for(int i=6; i<=n; i+=2) {
        dp[i] = (dp[i-2] * (i-1))%MOD;
    }
    cout << dp[n];
}