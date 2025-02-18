#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

const int mxN = 2010;
int n, m;
vector<int> arr[mxN];
int cap[mxN][mxN]; int flo[mxN][mxN];
int par[mxN];

int bfs(int S, int E) {
    memset(par, -1, sizeof(par));
    queue<pair<int, int>> q;
    q.push({S, INF});

    while(!q.empty()) {
        int cur = q.front().first;
        int cur_flow = q.front().second;
        q.pop();
        
        for(int nxt : arr[cur]) {
            if(par[nxt] == -1 && cap[cur][nxt] - flo[cur][nxt] > 0) {
                par[nxt] = cur;
                int flow = min(cur_flow, cap[cur][nxt] - flo[cur][nxt]);

                if(nxt == E) return flow;
                q.push({nxt, flow}); 
            }
        }
    }

    return 0;
}

int max_flow(int S, int E) {
    int ans = 0;

    while(1) {
        int new_flow = bfs(S, E);
        if(new_flow == 0) break;

        ans += new_flow;

        int now = E;
        while(now != S) {
            int prev = par[now];
            flo[prev][now] += new_flow;
            flo[now][prev] -= new_flow;
            now = prev;
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    int s = 0, e = n + m + 1;

    for(int i=1; i<=n; i++) {
        int q; cin >> q;
        while(q--) {
            int x; cin >> x;
            int tt = x + n;
            cap[i][tt] = 1;
            arr[i].push_back(tt);
            arr[tt].push_back(i);
        }
    }

    for(int i=1; i<=n; i++) {
        cap[s][i] = 2;
        arr[s].push_back(i);
        arr[i].push_back(s);
    }
    for(int i=1+n; i<=m+n; i++) {
        cap[i][e] = 1;
        arr[i].push_back(e);
        arr[e].push_back(i);
    }

    cout << max_flow(s, e);
}
