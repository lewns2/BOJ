#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define INFL 1e18
#define INF 1e9

const int mxN = 1e5+20;
int n, m;
vector<int> arr[mxN], rarr[mxN];
vector<vector<int>> scc;
stack<int> st;
int vis[mxN], par[mxN], degree[mxN];
vector<int> connect[mxN];

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
    scc[node].push_back(v);
    par[v] = node;

    for(auto next : rarr[v]) {
        if(!vis[next]) {
            rdfs(next, node);
        }
        if(par[v] != par[next]) {
            degree[par[v]]++;
            connect[par[next]].push_back(par[v]);
        }
    }
}

bool cdfs(int v, int c) {
    vis[v] = 1;
    for(auto next : connect[v]) {
        if(!vis[next]) {
            cdfs(next, c);
        }
    }

    for(int i=1; i<=c; i++) {
        if(vis[i] == 0) return false;
    }
    return true;
}

void init() {
    for(int i=0; i<=n; i++) {
        arr[i].clear();
        rarr[i].clear();
        connect[i].clear();
    }
    scc.clear();   
    memset(par, 0, sizeof(par));
}



int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
    int t; cin >> t;
    while(t--) {
        cin >> n >> m;

        for(int i=0; i<m; i++) {
            int fr, to; cin >> fr >> to;
            arr[fr].push_back(to);
            rarr[to].push_back(fr);
        }

        memset(vis, 0, sizeof(vis));
        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                dfs(i);
            }
        }

        memset(vis, 0, sizeof(vis));
        memset(degree, 0, sizeof(degree));

        int cnt = 0;
        while(st.size()) {
            int x = st.top();
            st.pop();

            if(vis[x]) continue;
            scc.resize(++cnt);
            rdfs(x, cnt-1);
        }

        int ans = 0, pos = 0;
        for(int i=0; i<cnt; i++) {
            sort(scc[i].begin(), scc[i].end());
            if(degree[i] == 0) {
                ans++;
                pos = i;
            }
        }
        
        if(ans != 1) {
            cout << "Confused" << "\n";
        }
        else {
            for(int i=0; i<scc[pos].size(); i++) {
                cout << scc[pos][i] << "\n";
            }
        }
        cout << "\n";
        init();

    }
}