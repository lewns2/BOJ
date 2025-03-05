#include <bits/stdc++.h>
using namespace std;

#define INF 1e9

const int mxN = 310; 
int n, m;
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
                int nxt_flow = min(cur_flow, cap[cur][nxt] - flo[cur][nxt]);
                if(nxt == E) return nxt_flow; 
                q.push({nxt, nxt_flow});

            }
        }
    }
    return 0;
}


int max_flow(int S, int E) {
    int ans = 0;

    while(1) {
        int plus_flow = bfs(S, E);
        if(plus_flow == 0) break;

        ans += plus_flow;
        int now = E;
        while(now != S) {
            int prev = par[now];
            flo[prev][now] += plus_flow;
            flo[now][prev] -= plus_flow;
            now = prev;
        }
    }

    return ans;

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    memset(cap, 0, sizeof(cap));
    
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int a, b, c; cin >> a >> b >> c;
        
        int A = min(a, b);
        int B = max(a, b);
        
        cap[A][B] += c;
        cap[B][A] += c;

        arr[A].push_back(B);
        arr[B].push_back(A);
    }

    cout << max_flow(1, n);
   
}