#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 2e18
#define INF 1e9

const int mxN = 50500;
int n;
vector<vector<int>> arr;
int dp[mxN][30];
int depth[mxN];
bool vis[mxN];

void dfs(int v, int d) {
    vis[v] = true;
    depth[v] = d;

    for(int i=0; i<arr[v].size(); i++) {
        int next = arr[v][i];
        if(!vis[next]) {
            dp[next][0] = v;
            dfs(next, d+1); 
        }
    }
}

void init() {
    for(int j=1; j<30; j++) {
        for(int i=1; i<=n; i++) {
            dp[i][j] = dp[ dp[i][j-1] ][j-1];
        }        
    }
}

int lca(int u, int v) {
    if(depth[u] < depth[v]) swap(u, v);
    int diff = depth[u] - depth[v];

    for(int i=0; diff; i++) {
        if(diff & 1) {
            u = dp[u][i];
        }
        diff >>= 1;
    }

    if(u == v) return u;

    for(int i=29; i>-1; i--) {
        if(dp[u][i] != dp[v][i]) {
            u = dp[u][i];
            v = dp[v][i];
        }
    }
    return dp[u][0];

}

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    arr.resize(n + 10);
    for(int i=0; i<n-1; i++) {
        int fr, to; cin >> fr >> to;
        arr[fr].push_back(to);
        arr[to].push_back(fr);
    }

    dfs(1, 0);
    init();

    int m; cin >> m;
    while(m--) {
        int a, b; cin >> a >> b;
        cout << lca(a, b) << "\n";
    }
}

