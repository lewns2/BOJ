#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9

const int mxN = 1e4+20;
int n, m, s, t;
vector<int> arr[mxN];
vector<int> rarr[mxN];
vector<vector<int>> scc;
stack<int> st;
vector<int> ct[mxN];
int vis[mxN], par[mxN], degree[mxN];
int dp[mxN], sccVis[mxN];

void dfs(int v) {
    vis[v] = 1;
    for(auto next : arr[v]) {
        if(!vis[next]) {
            dfs(next);
        }
    }
    st.push(v);
}

void rdfs(int v, int node) {
    vis[v] = 1;
    par[v] = node;
    scc[node].push_back(v);

    for(auto next : rarr[v]) {
        if(!vis[next]) {
            rdfs(next, node);
        }
        else if(par[v] != par[next]) {
            degree[par[v]]++;
            ct[par[next]].push_back(par[v]);
        }
    }
}

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> s >> t;
    for(int i=0; i<m; i++) {
        int fr, to; cin >> fr >> to;
        arr[fr].push_back(to);
        rarr[to].push_back(fr);
    }

    for(int i=1; i<=n; i++) {
        if(!vis[i]) {
            dfs(i);
        }
    }

    memset(vis, 0, sizeof(vis));
    int cnt = 0;
    while(st.size()) {
        int x = st.top();
        st.pop();

        if(vis[x]) continue;
        scc.resize(++cnt);
        rdfs(x, cnt-1);
    }
    int start = par[s];
    int end = par[t];

    queue<int> q;
    for(int i=0; i<cnt; i++) {
        dp[i] = scc[i].size();
        if(degree[i] == 0) {
            q.push(i);
        }
    }

    sccVis[start] = 1;
    
    while(q.size()) {
        int now = q.front();
        q.pop();

        for(auto next : ct[now]) {

            if(sccVis[now]) {
                sccVis[next] = 1;
                dp[next] = max(dp[next], dp[now] + (int)scc[next].size());
            }
             
            if(--degree[next] == 0) {
                q.push(next);
            }
        }
    }

    // for(int i=0; i<cnt; i++) {
    //     for(int j=0; j<scc[i].size(); j++) {
    //         cout << scc[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // for(int i=0; i<cnt; i++) {
    //     for(int j=0; j<ct[i].size(); j++) {
    //         cout << ct[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    if(sccVis[end]) {
        cout << dp[end];
    }
    else cout << 0;

} 