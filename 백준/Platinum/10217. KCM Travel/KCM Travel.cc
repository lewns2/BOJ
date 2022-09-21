#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9

int n, m, k;

int dist[101][10001];

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while(t--) {
        
        cin >> n >> m >> k;
        vector<pair<int, pair<int, int>>> ar[n+1];

        while(k--) {
            int a, b, c, d; cin >> a >> b >> c >> d;
            ar[a].push_back({b, {c, d}});
        }
        
        for(int i=0; i<=n; i++) {
            for(int j=0; j<=m; j++) {
                dist[i][j] = INF;
            }
        }
        dist[1][0] = 0;

        priority_queue<pair<int, pair<int, int>>> q;
        q.push({0, {0, 1}});

        while(q.size()) {
            int now_dist = -q.top().first;
            int now_cost = q.top().second.first;
            int now = q.top().second.second;
            q.pop();

            if(dist[now][now_cost] < now_dist) continue;

            for(auto nxt : ar[now]) {
                int next = nxt.first;
                int nextcost = nxt.second.first + now_cost;
                int nextdist = nxt.second.second + now_dist;

                if(nextcost > m) continue;
                if(dist[next][nextcost] <= nextdist) continue;

                dist[next][nextcost] = nextdist;
                
                for(int i=nextcost+1; i<=m; i++) {
                    if(dist[next][i] <= nextdist) break;
                    dist[next][i] = nextdist;
                }
                
                q.push({-nextdist, {nextcost, next}});
            }
        }  
        int ans = INF;
        for(int i=0; i<=m; i++) {
            ans = min(ans, dist[n][i]);
        }
        if(ans != INF) cout << ans << "\n";
        else cout << "Poor KCM" << "\n";
    }
}
