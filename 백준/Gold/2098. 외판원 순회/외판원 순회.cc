#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9

const int mxN = 17;
ll n, ar[17][17];
ll dp[17][1<<16];

ll solve(int v, int vis) {

    if(vis == (1<<n) - 1) {
        if(ar[v][0] == 0) return INF;
        return ar[v][0];
    }
    
    if(dp[v][vis] != -1) return dp[v][vis];
    dp[v][vis] = INF;
    
    for(int i=0; i<n; i++) {
        if(vis & (1<<i)) continue;
        if(ar[v][i] == 0) continue;

        ll ret = solve(i, vis|(1<<i));
        if(ret == 0) continue;
        dp[v][vis] = min(dp[v][vis], ret + ar[v][i]);
    }
    return dp[v][vis];
}

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> ar[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));
    
    cout << solve(0, 1);

} 

/*
dp[i][bit] = 현재 I 도시, 방문한 도시들의 최소값

if(ar[i][j] == 0) continue; || if(bit|(1<<j)) continue
dp[i][bit|(1<<j)] = min : dp[i][bit|(1<<j)], dp[i] + ar[i][j]
*/
