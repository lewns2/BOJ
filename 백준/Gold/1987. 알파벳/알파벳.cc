#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9

const int mxN = 21, dx[4]={1, -1, 0, 0}, dy[4]={0, 0, 1, -1};
int n, m;
int ar[mxN][mxN], vis[mxN][mxN];
int ans = 0;

void dfs(int x, int y, int cur, int dist) {
    
    ans = max(ans, dist);

    for(int k=0; k<4; k++) {
        int nx = x+dx[k];
        int ny = y+dy[k];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if(cur & (1<<ar[nx][ny])) continue;

        dfs(nx, ny, cur|(1<<ar[nx][ny]), dist+1);
    }
}

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            char x; cin >> x;
            ar[i][j] = x - 'A';
        }
    }

    int init = (1<<26);
    int num = ar[0][0];
    init = init|(1<<num);

    dfs(0, 0, init, 1);
    cout << ans;
}
