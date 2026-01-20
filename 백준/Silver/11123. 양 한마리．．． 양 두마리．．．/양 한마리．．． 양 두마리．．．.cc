#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define INFL 1e18
#define INF 1e9

int t, n, m;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

char arr[110][110];
int vis[110][110];

void dfs(int x, int y) {

    vis[x][y] = 1;

    for(int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx < 0 || nx >= n || ny < 0 || ny > m) continue;
        if(!vis[nx][ny] && arr[nx][ny] == '#') {
            dfs(nx, ny);
        }
    }

    return;

}

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> t;
    
    while(t--) {
        cin >> n >> m;

        for(int i=0; i<100; i++) {
            for(int j=0; j<100; j++) {
                arr[i][j] = '.';
                vis[i][j] = 0;
            }
        }

        for(int i=0; i<n; i++) {
            string s; cin >> s;
            for(int j=0; j<s.size(); j++) {
                arr[i][j] = s[j];
            }
        }

        int ans = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(arr[i][j] == '#' && !vis[i][j]) {
                    dfs(i, j);
                    ans++;
                }
            }    
        }

        cout << ans << "\n";  
    }
}

