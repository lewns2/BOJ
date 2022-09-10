#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9

const int mxN = 1e3+10;
int n, ar[mxN];
int dp[mxN];

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> ar[i];
    }
    for(int i=0; i<n; i++) {
        dp[i] = INF;
    }
    dp[0] = 0;
    for(int i=0; i<n; i++) {
        if(ar[i] == 0) continue;
        for(int j=i+1; j<=i+ar[i]; j++) {
            dp[j] = min(dp[j], dp[i]+1);
        }

    }
    if(dp[n-1] == INF) cout << -1;
    else cout << dp[n-1];

}