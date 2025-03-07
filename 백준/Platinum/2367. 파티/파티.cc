#include <bits/stdc++.h>
using namespace std;

#define INF 1e9

const int mxN = 400;
int n, k, d;
vector<int> arr[mxN];
int cap[mxN][mxN], flo[mxN][mxN];
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
        int in_flow = bfs(S, E);
        if(in_flow == 0) break;

        ans += in_flow;
        int now = E;
        while(now != S) {
            int prev = par[now];
            flo[prev][now] += in_flow;
            flo[now][prev] -= in_flow;
            now = prev;
        }
    }

    return ans;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k >> d;
    int s = 0, e = n+d+1;

    for(int i=1; i<=n; i++) {
        cap[s][i] = k;  // start -> person
        arr[s].push_back(i);
        arr[i].push_back(s);
    }

    for(int i=1; i<=d; i++) {
        int x; cin >> x;
        int xx = i+n;
        cap[xx][e] = x; // food -> end
        arr[xx].push_back(e);
        arr[e].push_back(xx);
    }
    for(int i=1; i<=n; i++) {
        int q; cin >> q;
        while(q--) {
            int x; cin >> x; // person - food
            int xx = x+n;
            cap[i][xx] = 1;
            arr[i].push_back(xx);
            arr[xx].push_back(i);
        }
    }

    cout << max_flow(s, e);
   
}