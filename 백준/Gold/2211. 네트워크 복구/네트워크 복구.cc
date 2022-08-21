#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9

const int mxN = 1e3+10;
int n, m;
vector<pair<int, int>> ar[mxN];
int dist[mxN], par[mxN];

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int a, b, c; cin >> a >> b >> c;
        ar[a].push_back({b, c});
        ar[b].push_back({a, c});
    }

    for(int i=1; i<=n; i++) {
        par[i] = i;
    }

    for(int i=0; i<=n; i++) {
        dist[i] = INF;
    }
    dist[1] = 0;
    priority_queue<pair<int, int>> q;
    q.push({dist[1], 1});

    while(q.size()) {
        int cost = -q.top().first;
        int now = q.top().second;
        q.pop();

        if(dist[now] < cost) continue;

        for(auto next : ar[now]) {
            if(dist[next.first] > dist[now] + next.second) {
                dist[next.first] = dist[now] + next.second;
                par[next.first] = now;
                q.push({-dist[next.first], next.first});
            }
        }
    }
    cout << n-1 << "\n";
    for(int i=2; i<=n; i++) {
        cout << i << " " << par[i] << "\n";
    }
}