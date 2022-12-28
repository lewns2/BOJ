#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define INF 1e9

const int mxN = 2e5+10;
int n, m;
vector<int> ar[mxN];
vector<int> rar[mxN];
vector<vector<int>> scc;
stack<int> st;
int vis[mxN];

void dfs(int v) {	
	vis[v] = 1;
	for(auto next : ar[v]) {
		if(!vis[next]) {
			dfs(next);
		}
	}
	st.push(v);
}

void rdfs(int v, int node) {
	vis[v] = 1;
	scc[node].push_back(v);

	for(auto next : rar[v]) {
		if(!vis[next]) {
			rdfs(next, node);
		}
	}
}

int main() {
	cin >> n >> m;
	for(int i=0; i<m; i++) {
		int a, b; cin >> a >> b;
		ar[a].push_back(b);
		rar[b].push_back(a);
	}

	for(int i=1; i<=n; i++) {
		if(!vis[i]) dfs(i);
	}

	int cnt = 0;
	memset(vis, 0, sizeof(vis));
	while(st.size()) {
		int now = st.top();
		st.pop();

		if(vis[now]) continue;
		scc.resize(++cnt);
		rdfs(now, cnt-1);
	}

	if(cnt == 1) cout << "Yes";
	else cout << "No";
} 