#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9

const int mxN = 1e3+10, dx[4]={1, -1, 0, 0}, dy[4]={0, 0, 1, -1};
int n, m, k;
int ar[mxN][mxN], vis[mxN][mxN];

void bfs(int x, int y, int s) {
    queue<pair<int, int>> q;
    q.push({x, y});
    vis[x][y] = 1;
    
    while(q.size()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int k=0; k<4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(!vis[nx][ny] && ar[nx][ny] <= s) {
                vis[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }
}

int solve(int s) {
    memset(vis, 0, sizeof(vis));
    for(int j=0; j<m; j++) {
        if(ar[0][j] <= s && !vis[0][j]) {
            bfs(0, j, s);
        }
    }
    for(int i=0; i<n; i++) {
        if(ar[i][0] <= s && !vis[i][0]) {
            bfs(i, 0, s);
        }
    }
    for(int i=0; i<n; i++) {
        if(ar[i][m-1] <= s && !vis[i][m-1]) {
            bfs(i, m-1, s);
        }
    }
    int res = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(vis[i][j]) res++;   
        }
    }
    return res;
} 

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> k;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> ar[i][j];
        }
    }
    int lo = 0, hi = 1000001;
    while(lo <= hi) {
        int mid = (lo + hi) / 2;
        if(solve(mid) >= k) {
            hi = mid-1;
        }
        else {
            lo = mid+1;
        }
    }
    cout << lo;
}
