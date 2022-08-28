#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9

const int mxN = 21, dx[4]={1, -1, 0, 0}, dy[4]={0, 0, 1, -1};
int n, m;
int ar[mxN][mxN], vis[mxN][mxN];

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

    queue<pair<int, pair<int, int>>> q;
    q.push({init, {0, 0}});

    int ans = 0;
    while(q.size()) {
        int cur = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();

        int tmp = 0;
        for(int i=0; i<26; i++) {
            if(cur & (1<<i)) tmp++;
        }
        ans = max(ans, tmp);

        for(int k=0; k<4; k++) {
            int nx = x+dx[k];
            int ny = y+dy[k];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(cur & (1<<ar[nx][ny])) continue;            
            q.push({cur|(1<<ar[nx][ny]), {nx, ny}});
        }
    }
    cout << ans;
}
