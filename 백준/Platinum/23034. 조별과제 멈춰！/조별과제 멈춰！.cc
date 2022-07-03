#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define INFL 1e18
#define INF 1e9

const int mxN = 1e3+20;
int n, m;
vector<pair<int, pair<int, int>>> arr;
vector<pair<int, int>> adj[mxN];
int par[mxN], dist[mxN][mxN];


int find(int x) {
    if(par[x] == x) return x;

    return par[x] = find(par[x]);
}

bool merge(int a, int b) {
    a = find(a);
    b = find(b);
    if(a == b) return false;
    if(a < b) swap(a, b);
    par[a] = b;
    return true;
}

void dfs(int start, int v, int mx, int p = -1) {
    
    dist[start][v] = mx;
    
    for(auto nxt : adj[v]) {
        int next = nxt.first;
        int nextcost = nxt.second;
        if(next != p) {
            dfs(start, next, max(mx, nextcost), v);
        }
    }
}

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        par[i] = i;
    }
    for(int i=0; i<m; i++) {
        int fr, to, val; cin >> fr >> to >> val;
        arr.push_back({val, {fr, to}});
        arr.push_back({val, {to, fr}});
    }
    sort(arr.begin(), arr.end());

    int ans = 0;
    for(int i=0; i<arr.size(); i++) {
        int cost = arr[i].first;
        int a = arr[i].second.first;
        int b = arr[i].second.second;
        
        if(merge(a, b)) {
            adj[a].push_back({b, cost});
            adj[b].push_back({a, cost});
            ans += cost;
        }
    }
    
    for(int i=1; i<=n; i++) {
        dfs(i, i, 0);
    }

    int q; cin >> q;
    while(q--) {
        int x, y; cin >> x >> y;
        cout << ans - dist[x][y] << "\n";
    }
}
