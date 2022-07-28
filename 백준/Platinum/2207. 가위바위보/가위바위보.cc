#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9

const int mxN = 2*1e4+10;
int n, m, q;
vector<int> arr[mxN];
vector<int> rarr[mxN];
vector<vector<int>> scc;
stack<int> st;
int vis[mxN], par[mxN];

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
    }
}

int rev(int x) {
    return x > n ? x - n : x + n;
} 

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> q >> n;
    for(int i=0; i<q; i++) {
        int a, b; cin >> a >> b;
        if(a < 0) a = -a + n;
        if(b < 0) b = -b + n;
        arr[rev(a)].push_back(b);
        arr[rev(b)].push_back(a);
        rarr[a].push_back(rev(b));
        rarr[b].push_back(rev(a));
    }

    for(int i=1; i<=2*n; i++) {
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
    bool flag = 1;
    for(int i=1; i<=n; i++) {
        if(par[i] == par[i+n]) {
            flag = 0;
            break;
        }
    }
    if(flag) cout << "^_^";
    else cout << "OTL";
    
} 

/*
*/
