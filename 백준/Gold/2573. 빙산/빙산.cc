#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define INFL 1e18
#define INF 1e9

const int mxN = 330, dx[4]={1, -1, 0, 0}, dy[4]={0, 0, 1, -1};
int n, m;
int arr[mxN][mxN];
int vis[mxN][mxN];
vector<pair<pair<int, int>, int>> space;
int ans = 0;

bool e(int x, int y) {
    return x < 0 || x >= n || y < 0 || y >= m;
}

void find(int x, int y) {
    int cnt = 0;
    for(int k=0; k<4; k++) {
        int nx = x+dx[k];
        int ny = y+dy[k];
        if(!e(nx, ny) && arr[nx][ny] == 0) {
            cnt++;
        }
    }
    space.push_back({{x, y}, cnt});
}

void melt() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(arr[i][j] == 0) continue;
            find(i, j);
        }
    } 

    for(int i=0; i<space.size(); i++) {
        int a = space[i].first.first;
        int b = space[i].first.second;
        int c = space[i].second;
        arr[a][b] -= c;
        if(arr[a][b] < 0) arr[a][b] = 0;
    }
}

void dfs(int x, int y) {
    vis[x][y] = 1;

    for(int k=0; k<4; k++) {
        int nx = x+dx[k];
        int ny = y+dy[k];
        if(!e(nx, ny) && !vis[nx][ny] && arr[nx][ny] != 0) {
            dfs(nx, ny);
        }
    }
}


int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    int mx = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> arr[i][j];
            mx = max(mx, arr[i][j]);
        }
    }
    bool flag = false;
    int count = 0;
    while(1) {
        count++;
        memset(vis, 0, sizeof(vis));
        space.clear();

        melt();
        ans = 0;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(!vis[i][j] && arr[i][j] != 0) {
                    ans++;
                    dfs(i, j);
                }
            }
        }

        if(ans >= 2) {
            cout << count;
            break;
        }
        if(space.size() == 0 && ans <= 1) {
            cout << 0;
            break;
        }
    }
    
}