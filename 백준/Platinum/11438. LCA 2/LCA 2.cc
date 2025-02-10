#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define INFL 2e18
#define INF 1e9

const int mxN = 1e5+10, mxM = 1e5, LOG = 20; // 1e5
int n, m;
vector<int> arr[mxN];
int par[mxN][LOG];
int depth[mxN];

void dfs(int v, int p , int d) {
    par[v][0] = p;
    depth[v] = d;

    for(int i=0; i<arr[v].size(); i++) {
        int nxt = arr[v][i];
        if(nxt == par[v][0]) continue;
        dfs(nxt, v, d+1);
    }
}

void make_table() {
    for(int j=1; j<LOG; j++) {
        for(int i=1; i<=n; i++) {
            par[i][j] = par[par[i][j-1]][j-1];
        }
    }
}

int lca(int x, int y) {
    if(depth[x] < depth[y]) swap(x, y);
    int diff = depth[x] - depth[y];
    for(int i=0; i<LOG; i++) {
        if(diff & (1<<i)) {
            x = par[x][i];
        }    
    }

    if(x == y) return x;

    for(int i=LOG-1; i>=0; i--) {
        if(par[x][i] != par[y][i]) {
            x = par[x][i];
            y = par[y][i];
        }
    }
    
    return par[x][0];
}

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i=0; i<n-1; i++) {
        int a, b; cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }    

    dfs(1, -1, 1); // root, par, depth

    make_table();

    cin >> m;
    while(m--) {
        int x, y; cin >> x >> y;
        cout << lca(x, y) << "\n";
    }

 }