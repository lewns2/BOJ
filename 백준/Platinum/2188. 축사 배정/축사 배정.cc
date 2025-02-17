#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define INFL 2e18
#define INF 1e9

const int mxN = 420; 
int n, m;
vector<int> arr[mxN];
int cap[mxN][mxN]; int flo[mxN][mxN];
int par[mxN];

int bfs(int s, int e) {
    memset(par, -1, sizeof(par));
    queue<pair<int, int>> q;
    q.push({s, INF});

    while(!q.empty()) {
        int cur = q.front().first;
        int curFlow = q.front().second;
        q.pop();

        for(int nxt : arr[cur]) {
            if(par[nxt] == -1 && cap[cur][nxt] - flo[cur][nxt] > 0) {
                par[nxt] = cur;
                int flow = min(cap[cur][nxt] - flo[cur][nxt], curFlow);

                if(nxt == e) return flow;
                q.push({nxt, flow});
            }
        }
    }

    return 0;

}


int maxFlow(int s, int e) {
    int ans = 0;

    while(1) {
        int nFlow = bfs(s, e);
        if(nFlow == 0) break;
        
        ans += nFlow;
        int now = e;

        while(now != s) {
            int prev = par[now];
            flo[prev][now] += nFlow;
            flo[now][prev] -= nFlow;

            now = prev;
        }   
    }

    return ans;

}

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    
    int s = 0, e = n + m + 1;

    for(int i=1; i<=n; i++) {
        int q; cin >> q;

        while(q--) {
            int x; cin >> x;
            int tmp = x + n;
            arr[i].push_back(tmp);
            arr[tmp].push_back(i);
            cap[i][tmp] = 1;
        }
    }

    for(int i=1; i<=n; i++) {
        arr[s].push_back(i);
        arr[i].push_back(s);
        cap[s][i] = 1;
    }
    for(int i=1; i<=m; i++) {
        int x = i + n;
        arr[x].push_back(e);
        arr[e].push_back(x);
        cap[x][e] = 1;
    }

    cout << maxFlow(s, e);


} 