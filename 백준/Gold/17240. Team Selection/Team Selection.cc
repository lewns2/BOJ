#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9

const int mxN = 2e4+10;
ll n, ar[20050][8];
int dp[20050][8];
int order[6], vis[6];
ll ans = 0;

void solve() {

    ll cal[20050][8];
    memset(cal, 0, sizeof(cal));
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=5; j++) {
            int x = order[j-1];
            cal[i][j] = max(cal[i-1][j], cal[i-1][j-1] + ar[i][x]);
        }
    }
    ans = max(ans, cal[n][5]);
}

void recur(int cur = 0) {
    if(cur == 5) {
        solve();
    }

    for(int i=1; i<=5; i++) {
        if(vis[i]) continue;
        vis[i] = 1;
        order[cur] = i;
        recur(cur+1);
        vis[i] = 0;
    }
}

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=5; j++) {
            cin >> ar[i][j];
        }
    }

    recur();
    cout << ans;
} 
