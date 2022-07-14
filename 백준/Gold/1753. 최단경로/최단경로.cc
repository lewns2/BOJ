#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9

const int mxN = 2e5+20;
int n, m;
vector<pair<int, int>> arr[mxN];
int dist[mxN];

void bfs(int x) {

    priority_queue<pair<int, int>> pq;
    pq.push({dist[x], x});

    while(pq.size()) {
        int cost = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if(dist[now] > cost) continue;
        
        for(int i=0; i<arr[now].size(); i++) {
            int next = arr[now][i].first;
            int nextcost = arr[now][i].second;

            if(dist[next] > dist[now] + nextcost) {
                dist[next] = dist[now] + nextcost;
                pq.push({-dist[next], next});
            }
        }
    }
}

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    int s; cin >> s;

    for(int i=0; i<m; i++) {
        int fr, to, val; cin >> fr >> to >> val;
        arr[fr].push_back({to, val});
    }
    for(int i=1; i<=n; i++) {
        dist[i] = INF;
    }
    dist[s] = 0;
    bfs(s);
    for(int i=1; i<=n; i++) {
        if(dist[i] == INF) {
            cout << "INF" << "\n";
        }
        else {
            cout << dist[i] << "\n";
        }
    }

} 