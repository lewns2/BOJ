#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9

const int mxN = 1e3+10, dx[4]={1, -1, 0, 0}, dy[4]={0, 0, 1, -1};
int n, m;
int ar[mxN][mxN], vis[mxN][mxN];

void dfs(int x, int y) {
    vis[x][y] = 1;

    for(int k=0; k<4; k++) {
        int nx = x+dx[k];
        int ny = y+dy[k];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if(!vis[nx][ny] && ar[nx][ny] == 0) {
            dfs(nx, ny);
        }
    }
}

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        string s; cin >> s;
        for(int j=0; j<m; j++) {
            ar[i][j] = s[j] - '0';
        }
    }
    memset(vis, 0, sizeof(vis));
    for(int i=0; i<m; i++) {
        if(ar[0][i] == 0 && !vis[0][i]) dfs(0, i);
    }
    bool ok = true;
    for(int i=0; i<m; i++) {
        if(vis[n-1][i]) {
            ok = false;
            break;
        }
    }
    
    if(!ok) cout << "YES";
    else cout << "NO";
}