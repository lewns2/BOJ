#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9

ll ar[20005][5];
ll dp[20005][1<<5];

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    for(int i=1; i<=n; i++) {
        for(int j=0; j<5; j++) {
            cin >> ar[i][j];
        }
    }


    ll ans = 0;
    for(int i=1; i<=n; i++) {

        for(int j=0; j<(1<<j); j++) {
            dp[i][j] = dp[i-1][j];
        }
        for(int j=0; j<5; j++) {
            for(int k=0; k<(1<<5); k++) {
                if(k & (1<<j)) continue;
                dp[i][k|(1<<j)] = max(dp[i][k|(1<<j)], dp[i-1][k] + ar[i][j]);
            }
        }
        ans = max(ans, dp[i][(1<<5)-1]);
    }
    cout << ans;

}

