#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9

const int mxN = 1e5+100;
int a, b, n, m;
int dist[mxN];

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> a >> b >> n >> m;
    int dx[8] = {1, -1, a, b, -a, -b, a, b};

    for(int i=0; i<=100000; i++) dist[i] = INF;
    dist[n] = 0;

    priority_queue<pair<int, int>> q;
    q.push({0, n});

    while(q.size()) {
        int cnt = -q.top().first;
        int now = q.top().second;
        q.pop();

        for(int k=0; k<6; k++) {
            int next = now + dx[k];
            if(next < 0 || next > 100000) continue;
            if(dist[next] > dist[now] + 1) {
                dist[next] = dist[now] + 1;
                q.push({-dist[next], next});
            }
        }
        for(int k=6; k<8; k++) {
            int next = now * dx[k];
            if(next < 0 || next > 100000) continue;
            if(dist[next] > dist[now] + 1) {
                dist[next] = dist[now] + 1;
                q.push({-dist[next], next});
            }
        }
    }
    cout << dist[m];
    

}