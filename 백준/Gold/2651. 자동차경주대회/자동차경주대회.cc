#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9

const int mxN = 105;
ll n, k, tot = 0;
ll ar[mxN], road[mxN], cost[mxN];
ll dp[mxN]; // 최소 비용
int status;
vector<int> vis;

ll recur(int idx, ll dist) {

    if(dist + k >= tot) {
        return dp[idx];
    }

    if(dp[idx] != 0) return dp[idx];
    dp[idx] = INFL;

    for(int i=1; i<=n; i++) {
        if(road[i] > dist && road[i] <= dist + k) {
            ll ret = recur(i, road[i]);
            dp[idx] = min(dp[idx], ret + cost[i]);
        }
    }

    return dp[idx];
}

void trace(int pos) {
    if(pos > n) return;

    for(int i=pos+1; i<=n; i++) {
        if(dp[pos] - cost[i] == dp[i]) {
            vis.push_back(i);
            trace(i);
            break;
        }
    }
}


int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> k >> n;
    for(int i=1; i<=n+1; i++) {
        cin >> ar[i];
        road[i] = road[i-1] + ar[i]; // 정비소 위치
        tot += ar[i];   // 총 거리
    }
    for(int i=1; i<=n; i++) {
        cin >> cost[i];
    }
    memset(dp, 0, sizeof(dp));

    int ret = recur(0, 0);
    cout << ret << "\n";
    trace(0);
    cout << vis.size() << "\n";
    for(auto x : vis) cout << x << " ";

}
