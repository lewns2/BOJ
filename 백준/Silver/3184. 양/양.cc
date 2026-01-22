#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define INFL 1e18
#define INF 1e9

const int mxN = 255, dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
int n, m;
char arr[mxN][mxN];
int vis[mxN][mxN];
int wol = 0, shp = 0;
int answol = 0, ansshp = 0;

void dfs(int x, int y) {
    vis[x][y] = 1;

    if(arr[x][y] == 'v') wol++;
    if(arr[x][y] == 'o') shp++;

    for(int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if(!vis[nx][ny] && arr[nx][ny] != '#') {
            dfs(nx, ny);
        }
    }

    return;
}

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for(int i=0; i<n; i++) {
        string s; cin >> s;
        for(int j=0; j<s.size(); j++) {
            arr[i][j] = s[j];
        }
    }

    memset(vis, 0, sizeof(vis));

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(!vis[i][j] && arr[i][j] != '#') {
                wol = 0; shp = 0;
                dfs(i, j);
                
                if(shp > wol) ansshp += shp;
                else answol += wol;
            }
        }
    }

    cout << ansshp << " " << answol; 

}

