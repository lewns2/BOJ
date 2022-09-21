#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9

const int mxN = 1e5+20;
int n, m;
int par[mxN], pref[mxN], dp[mxN];
int vis[mxN];
vector<int> ar[mxN];

void dfs(int v) {
    vis[v] = 1;
    
    for(auto next : ar[v]) {
        if(!vis[next]) {
            dfs(next);
        }
        else {
            dp[v] = dp[next] + pref[v];
        }
    }
}

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        int x; cin >> x;
        par[i] = x;
        ar[i].push_back(x);
        ar[x].push_back(i);
    }

    while(m--) {
        int a, b; cin >> a >> b;
        pref[a] += b;
    }
    dfs(1);
    for(int i=1; i<=n; i++) {
        cout << dp[i] << " ";
    }
}
