#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 2e18
#define INF 1e9

const int mxN = 1e5 + 50;
int n;
vector<vector<int>> arr;
bool vis[mxN];
int depth[mxN]; 
int dp[mxN][30];

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
            dp[i][j] = dp[dp[i][j-1]][j-1];
        }
    }
}

int lca(int a, int b) {
    if(depth[a] < depth[b]) swap(a, b);
    int diff = depth[a] - depth[b];

    for(int i=0; diff; i++) {
        if(diff & 1) {
            a = dp[a][i];
        }
        diff >>= 1;
    }
    
    if(a == b) return a;

    for(int i=29; i>-1; i--) {
        if(dp[a][i] != dp[b][i]) {
            a = dp[a][i];
            b = dp[b][i];
        }
    }
    return dp[a][0];
    
}

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    arr.resize(n+10);
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

