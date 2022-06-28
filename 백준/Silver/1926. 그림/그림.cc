#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define INFL 1e18
#define INF 1e9

const int mxN = 550, dx[4]={1, -1, 0, 0}, dy[4]={0, 0, 1, -1};
int n, m;
int arr[mxN][mxN];
int vis[mxN][mxN];
int cnt = 0;

bool e(int x, int y) {
    return x>=0 && x<n && y>=0 && y<m && arr[x][y];
}

void dfs(int x, int y) {
    vis[x][y] = 1;
    cnt++;
    

    for(int k=0; k<4; k++) {
        int nx = x+dx[k];
        int ny = y+dy[k];
        if(!vis[nx][ny] && e(nx, ny)) {
            dfs(nx, ny);
        }   
    }
} 


int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> arr[i][j];
        }
    }

    int ans = 0, ans2 = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            
            if(arr[i][j] && !vis[i][j]) {
                ans++, cnt = 0;            
                dfs(i, j);
                ans2 = max(ans2, cnt);
            }
        }
    }
    cout << ans << "\n" << ans2 << "\n";
    
}
