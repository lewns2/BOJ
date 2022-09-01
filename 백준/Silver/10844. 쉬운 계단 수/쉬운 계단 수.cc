#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9

const int mxN = 110, MOD = 1e9;
int n;
int dp[mxN][10];

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    memset(dp, 0, sizeof(dp));

    for(int i=1; i<10; i++) {
        dp[1][i] = 1;
    }

    for(int i=2; i<=n; i++) {
        for(int j=0; j<10; j++) {
            if(j == 0) dp[i][j] = dp[i-1][j+1];
            else if(j == 9) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1])%MOD;
        }
    }
    int ans = 0;
    for(int i=0; i<10; i++) {
        ans = (ans + dp[n][i])%MOD;
    }
    cout << ans;

    // dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1];

}