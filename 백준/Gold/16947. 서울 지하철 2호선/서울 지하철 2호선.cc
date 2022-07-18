#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9

const int mxN = 3e3+10;
int n;
vector<int> arr[mxN];
int vis[mxN], par[mxN], ans[mxN];
vector<int> cycle;
int cnt = 0;

void dfs(int v, int pos = 0) {
    vis[v] = pos;

    for(auto next : arr[v]) {
        if(vis[next] < 0) {
            dfs(next, v);
        }
        else if(next != vis[v]) {
            cycle.push_back(v);
        }
    }
}

void trace(int start, int end) {
    int s = start;
    int target = end;
    while(1) {
        if(s == target) {
            par[s] = 1;
            break;
        }
        par[s] = 1;
        s = vis[s];
    }
}

void solve() {
    queue<pair<int, int>> q;
    for(int i=1; i<=n; i++) {
        if(par[i] != 0) {
            vis[i] = 1;
            q.push({i, 0});
        }
    }

    while(q.size()) {
        int now = q.front().first;
        int d = q.front().second;
        q.pop();
        vis[now] = 1;
        
        for(auto next : arr[now]) {
            if(!vis[next]) {
                ans[next] = d+1;
                q.push({next, d+1});
            }
        }
    }
}   

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++) {
        int fr, to; cin >> fr >> to;
        arr[fr].push_back(to);
        arr[to].push_back(fr);
    }

    memset(vis, -1, sizeof(vis)); 
    for(int i=1; i<=n; i++) {
        if(vis[i] < 0) {
            dfs(i);
        }
    }
    trace(cycle[0], cycle[1]);

    for(int i=1; i<=n; i++) {
        if(par[i] == 1) {
            ans[i] = 0;
        }
    }

    memset(vis, 0, sizeof(vis));
    solve();
    
    for(int i=1; i<=n; i++) {
        cout << ans[i] << " ";
    }
} 