#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define INFL 1e18
#define INF 1e9

const int mxN = 1e6+20;
int n, m;
vector<int> arr[mxN];
vector<int> rarr[mxN];
vector<vector<int>> scc;
stack<int> st;
int vis[mxN];

void dfs(int v) {
    vis[v] = 1;
    for(auto next : arr[v]) {
        if(!vis[next]) {
            dfs(next);
        }
    }
    st.push(v);
}

void rdfs(int v) {
    vis[v] = 1;
    for(auto next : arr[v]) {
        if(!vis[next]) {
            rdfs(next);
        }
    }
}

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int fr, to; cin >> fr >> to;
        arr[fr].push_back(to);
        rarr[to].push_back(fr);
    }

    for(int i=0; i<n; i++) {
        if(!vis[i]) {
            dfs(i);
        }
    }

    memset(vis, 0, sizeof(vis));
    int cnt = 0, ans = 0;
    while(st.size()) {
        int x = st.top();
        st.pop();
        
        if(vis[x]) continue;
        ans++;
        rdfs(x);
    }
    cout << ans;



}