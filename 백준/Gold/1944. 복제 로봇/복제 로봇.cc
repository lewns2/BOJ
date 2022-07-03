#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define INFL 1e18
#define INF 1e9

const int mxN = 255, dx[4]={1, -1, 0, 0}, dy[4]={0, 0, 1, -1};
int n, m, si, sj;
vector<pair<int, int>> space;
char arr[mxN][mxN];
int vis[mxN][mxN], dist[mxN][mxN];
int par[mxN];

bool e(int x, int y) {
    return x < 0 || x >= n || y < 0 || y >= n || arr[x][y] == '1';
}

void bfs(int x, int y, int start) {
    
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {x, y}});

    while(q.size()) {
        int d = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();

        if(arr[x][y] == 'K' || arr[x][y] == 'S') {
            for(int i=0; i<space.size(); i++) {
                if(space[i].first == x && space[i].second == y) {
                    dist[start][i] = d;
                }
            }
        }

        for(int k=0; k<4; k++) {
            int nx = x+dx[k];
            int ny = y+dy[k];
            if(e(nx, ny)) continue;
            if(!vis[nx][ny]) {
                vis[nx][ny] = 1;
                q.push({d+1, {nx, ny}});
            }
        }
    }
}

int find(int x) {
    if(par[x] == x) return x;
    return par[x] = find(par[x]);
}

bool merge(int a, int b) {
    a = find(a);
    b = find(b);
    if(a==b) return false;
    if(a < b) swap(a, b);
    par[a] = b;
    return true;
}

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        string s; cin >> s;
        for(int j=0; j<n; j++) {
            arr[i][j] = s[j];
            if(arr[i][j] == 'S') {
                si = i;
                sj = j;
                space.push_back({i, j});
            }
            if(arr[i][j] == 'K') {
                space.push_back({i, j});
            }
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            dist[i][j] = INF;
        }
        dist[i][i] = 0;
    }
    for(int i=0; i<space.size(); i++) {
        memset(vis, 0, sizeof(vis));
        bfs(space[i].first, space[i].second, i);
    }
    
    vector<pair<int, pair<int, int>>> adj;
    for(int i=0; i<space.size(); i++) {
        for(int j=0; j<space.size(); j++) {
            if(i == j) continue;
            adj.push_back({dist[i][j], {i, j}});
            adj.push_back({dist[i][j], {j, i}});   
        }
    }

    sort(adj.begin(), adj.end());
    for(int i=0; i<space.size(); i++) {
        par[i] = i;
    }

    int ans = 0;
    for(int i=0; i<adj.size(); i++) {
        int c = adj[i].first;
        int x = adj[i].second.first;
        int y = adj[i].second.second;
        if(merge(x, y)) {
            ans += c;
        }
    }
    if(ans >= INF || ans == 0) cout << -1;
    else cout << ans;

}