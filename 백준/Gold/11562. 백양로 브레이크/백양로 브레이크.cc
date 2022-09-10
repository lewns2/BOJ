#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9

const int mxN = 255;
int n, m;
int ar[mxN][mxN];
int dist[mxN][mxN];

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int a, b, c; cin >> a >> b >> c;
        if(c == 0) ar[a][b] = 1;
        else if(c == 1) {
            ar[a][b] = 1;
            ar[b][a] = 1;
        }
    }

    memset(dist, -1, sizeof(dist));

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(dist[i][j] == -1) dist[i][j] = INF;
            if(ar[i][j] == 1) {
                if(ar[j][i] == 1) {
                    dist[i][j] = 0;
                    dist[j][i] = 0;
                }
                else if(ar[j][i] == 0) {
                    dist[i][j] = 0;
                    dist[j][i] = 1;
                }

            }
        }
        dist[i][i] = 0;
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
        int fr, to; cin >> fr >> to;
        cout << dist[fr][to] << "\n";
    }

}
