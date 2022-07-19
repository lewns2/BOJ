#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9

const int mxN = 610, dx[4]={1, -1, 0, 0}, dy[4]={0, 0, 1, -1};
int n, m, si, sj; 
char arr[mxN][mxN];
int vis[mxN][mxN];

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        string s; cin >> s;
        for(int j=0; j<m; j++) {
            arr[i][j] = s[j];
            if(arr[i][j] == 'I') {
                si = i;
                sj = j;
            }
        }
    }

    memset(vis, 0, sizeof(vis));
    
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = 1;
    int ans = 0;
    while(q.size()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int k=0; k<4; k++) {
            int nx = x+dx[k];
            int ny = y+dy[k];

            if(nx < 0 || nx >=n || ny < 0 || ny >=m || arr[nx][ny] == 'X') continue;
            if(!vis[nx][ny]) {
                if(arr[nx][ny] == 'P') ans++;
                vis[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }
    if(ans == 0) cout << "TT";
    else cout << ans;
} 