#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9

const int mxN = 101, dx[4]={1, -1, 0, 0}, dy[4]={0, 0, 1, -1};
int n, m, t;
int ar[mxN][mxN];
int vis[mxN][mxN][2];
int ans = 1e9;

void bfs(int x, int y) {
    

    queue<pair<pair<int, int>, pair<int, int>>> q;
    q.push({{0, 0}, {x, y}});
    vis[x][y][0] = 1;
    
    while(q.size()) {
        int d = q.front().first.first;
        int key = q.front().first.second;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();

        if(d > t) continue;
        if(x == n-1 && y == m-1) {
            ans = min(ans, d);
        }

        for(int k=0; k<4; k++) {
            int nx = x+dx[k];
            int ny = y+dy[k];
            if(nx < 0 || nx>=n || ny<0 || ny >=m) continue;

            if(key == 1) {
                if(!vis[nx][ny][key]) {
                    vis[nx][ny][key] = 1;
                    q.push({{d+1, key}, {nx, ny}});
                }
            }
            else {
                if(!vis[nx][ny][key]) {
                    if(ar[nx][ny] == 0) {
                        vis[nx][ny][key] = 1;
                        q.push({{d+1, key}, {nx, ny}});
                    }                    
                    else if(ar[nx][ny] == 2) {
                        vis[nx][ny][key^1] = 1;
                        q.push({{d+1, key^1}, {nx, ny}});
                    }
                }
            }
        }
        
    }
}



int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> t;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> ar[i][j];
        }
    }
    bfs(0, 0);
    if(ans > t) {
        cout << "Fail";
    }
    else cout << ans;
} 