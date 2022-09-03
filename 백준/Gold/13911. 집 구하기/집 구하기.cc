#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9

const int mxN = 1e4+10;
int n, e, m, x, s, y;
vector<pair<int, int>> ar[mxN];
int dist[2][mxN];

void bfs(int s, int flag) {
    // flag = 0 => m / 1 => s
    dist[flag][s] = 0;

    priority_queue<pair<int, int>> q;
    q.push({0, s});

    while(q.size()) {
        int cost = -q.top().first;
        int now = q.top().second;
        q.pop();

        if(dist[flag][now] < cost) continue;

        for(auto nxt : ar[now]) {
            int next = nxt.first;
            int nextcost = nxt.second;
            
            if(dist[flag][next] > dist[flag][now] + nextcost) {
                dist[flag][next] = dist[flag][now] + nextcost;
                q.push({-dist[flag][next], next});
            }
        }
    }
}

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> e;
    for(int i=0; i<e; i++) {
        int a, b, c; cin >> a >> b >> c;
        ar[a].push_back({b, c});
        ar[b].push_back({a, c});
    }
    for(int i=0; i<2; i++) {
        for(int j=0; j<n+5; j++) {
            dist[i][j] = INF;
        }
    }
    cin >> m >> x;
    for(int i=0; i<m; i++) {
        int node; cin >> node;
        ar[n+1].push_back({node, 0});
    }
    cin >> s >> y;
    for(int i=0; i<s; i++) {
        int node; cin >> node;
        ar[n+2].push_back({node, 0});
    }
    bfs(n+1, 0);
    bfs(n+2, 1);
    int ans = 1e9;
    for(int i=1; i<=n; i++) {
        if(dist[0][i] == 0 || dist[1][i] == 0) continue;
        if(dist[0][i] > x || dist[1][i] > y) continue;
        ans = min(ans, dist[0][i] + dist[1][i]);
    }
    if(ans == 1e9) cout << -1;
    else cout << ans;
}