#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9

const int mxN = 1005;
int n;
int dp[mxN][10];

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    memset(dp, 0, sizeof(dp));

    for(int i=0; i<10; i++) dp[1][i] = 1;

    for(int i=2; i<=n; i++) {
        for(int j=0; j<10; j++) {
            if(j == 0) dp[i][j] = 1;
            else {
                dp[i][j] = (dp[i-1][j] + dp[i][j-1])%10007;
            }
        }
    }
    int ans = 0;
    for(int i=0; i<10; i++) {
        ans += dp[n][i];
    }
    cout << (ans % 10007);
}