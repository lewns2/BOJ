#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9

const int mxN = 1e3+10;
int n, k;
pair<int, int> pos[mxN];
int tele[mxN];
int dist[mxN][mxN];

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    for(int i=1; i<=n; i++) {
        int s, x, y; cin >> s >> x >> y;
        if(s == 1) tele[i] = 1;
        pos[i] = {x, y};
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            dist[i][j] = INF;
        }
        dist[i][i] = 0;
    }

    for(int i=1; i<=n; i++) {
        int a = pos[i].first;
        int b = pos[i].second;
        for(int j=1; j<=n; j++) {
            if(i == j) continue;
            int c = pos[j].first;
            int d = pos[j].second;
            if(tele[i] == 1 && tele[j] == 1) {
                dist[i][j] = min(k, abs(a - c) + abs(b - d));
            }
            else dist[i][j] = abs(a - c) + abs(b - d);
        }
    }
    
    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int q; cin >> q;
    while(q--) {
        int a, b; cin >> a >> b;
        cout << dist[a][b] << "\n";
    }
}
