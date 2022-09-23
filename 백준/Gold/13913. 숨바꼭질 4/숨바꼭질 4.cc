#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9

const int mxN = 100010, mx = 200001;
int n, k;
int dist[mxN*2], vis[mxN*2];

void bfs(int s, int e) {
    for(int i=0; i<=200000; i++) dist[i] = INF;
    dist[s] = 0;
    queue<pair<int, int>> q;
    q.push({0, s});

    while(q.size()) {
        int cnt = q.front().first;
        int now = q.front().second;
        q.pop();

        if(now == e) break;

        if(now * 2 < mx && dist[now*2] > cnt + 1) {
            dist[now*2] = cnt + 1;
            vis[now*2] = now;
            q.push({cnt+1, now*2});
        }
        if(now - 1 >= 0 && dist[now-1] > cnt + 1) {
            dist[now-1] = cnt + 1;
            vis[now-1] = now;
            q.push({cnt+1, now-1});
        }
        if(now+1 < mx && dist[now+1] > cnt + 1) {
            dist[now+1] = cnt + 1;
            vis[now+1] = now;
            q.push({cnt+1, now+1});
        }
    }
}

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    memset(dist, -1, sizeof(dist));
    bfs(n, k);
    cout << dist[k] << "\n";
    vector<int> pos;
    for(int i=k; i!=n; i=vis[i]) {
        pos.push_back(i);
    } pos.push_back(n);

    reverse(pos.begin(), pos.end());
    for(auto x : pos) cout << x << " ";
}
