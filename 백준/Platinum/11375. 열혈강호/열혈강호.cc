#include <bits/stdc++.h>
using namespace std;

#define INF 1e9
const int mxN = 1005, mxM = 1005;
int n, m;
vector<int> arr[mxN+mxM];
int cap[mxN+mxM][mxN+mxM]; int flo[mxN+mxM][mxN+mxM];
int par[mxN+mxM];


int bfs(int S, int E) {
    memset(par, -1, sizeof(par));
    queue<pair<int, int>> q;
    q.push({S, INF});

    while(!q.empty()) {
        int cur = q.front().first;
        int cur_flow = q.front().second;
        q.pop();

        for(int nxt : arr[cur]) {
            if(par[nxt] == -1 && cap[cur][nxt] - flo[cur][nxt] > 0) { // 다음 노드의 부모 값이 있다면 해당 노드를 방문한 것.
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
            arr[i].push_back(tt);
            arr[tt].push_back(i);
            cap[i][tt] = 1;
        }
    }

    for(int i=1; i<=n; i++) {
        arr[s].push_back(i);
        arr[i].push_back(s);
        cap[s][i] = 1;
    }
    for(int i=1; i<=m; i++) {
        int x = i+n;
        arr[x].push_back(e);
        arr[e].push_back(x);
        cap[x][e] = 1;
    }

    cout << max_flow(s, e);
}