#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9

const int mxN = 210;
int n, m;
int ar[mxN], A[mxN], vis[mxN];
int rep[mxN][mxN];
int tot = 0, ans = 0;

void recur(int cur, int idx) {
    if(cur == 3) {
        tot++;
        int x = A[0], y = A[1], z = A[2];
        if(rep[x][y] == 1 || rep[y][z] == 1 || rep[z][x] == 1) ans++;
        return;
    }

    for(int i=idx; i<n; i++) {
        if(vis[i]) continue;
        vis[i] = 1;
        A[cur] = ar[i];
        recur(cur+1, i);
        vis[i] = 0;
    }
}

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i=0; i<n; i++) ar[i] = i+1;

    memset(rep, 0, sizeof(rep));

    while(m--) {
        int a, b; cin >> a >> b;
        rep[a][b] = 1;
        rep[b][a] = 1;
    }

    recur(0, 0);
    cout << tot - ans;
}