#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9

const int mxN = 51, dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
int n, m, si, sj, ei, ej;
char ar[mxN][mxN];
int vis[mxN][mxN][1<<6];
set<char> st;
int ans = -1;

bool e(int x, int y) {
    return x < 0 || x >= n || y < 0 || y >= m || ar[x][y] == '#';
}

int bfs(int x, int y) {
    
    queue<pair<pair<int, int>, pair<int, int>>> q;
    q.push({{0, 0}, {x, y}});
    vis[x][y][0] = 1;

    while(q.size()) {
        int dist = q.front().first.first;
        int key = q.front().first.second;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();

        if(ar[x][y] == '1') {
            return dist;
        }

        for(int k=0; k<4; k++) {
            int nx = x+dx[k];
            int ny = y+dy[k];
            
            if(e(nx, ny)) continue;
            
            if(ar[nx][ny] == '0' || ar[nx][ny] == '1' || ar[nx][ny] == '.') {
                if(!vis[nx][ny][key]) {
                    vis[nx][ny][key] = 1;
                    q.push({{dist+1, key}, {nx, ny}});
                }
            }

            else if(ar[nx][ny] - 'a' >= 0 && ar[nx][ny] - 'a' <= 6) {
                if(vis[nx][ny][key]) continue;
                vis[nx][ny][key] = 1;
                
                int keynum = ar[nx][ny] - 'a';
                int nextkey = key | (1<<keynum);
                
                vis[nx][ny][nextkey] = 1;
                
                q.push({{dist+1, nextkey}, {nx, ny}});
            }

            else if(ar[nx][ny] - 'A' >= 0 && ar[nx][ny] - 'B' <= 6) {
                
                int keynum = ar[nx][ny] - 'A';

                if(key & (1<<keynum) && !vis[nx][ny][key]) {
                    vis[nx][ny][key] = 1;
                    q.push({{dist+1, key}, {nx, ny}});
                }
            }

        }
    }
    return -1;

}

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> ar[i][j];
            if(ar[i][j] == '0') {
                si = i;
                sj = j;
            }
            if(ar[i][j] == '1') {
                ei = i;
                ej = j;
            }
        }
    }
    cout << bfs(si, sj);
    
} 