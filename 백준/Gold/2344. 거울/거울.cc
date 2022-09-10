#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9

const int mxN = 1e3+10, dx[4]={1, -1, 0, 0}, dy[4]={0, 0, 1, -1};
int n, m;
int ar[mxN][mxN];
int num[mxN][mxN];

bool e(int x, int y) {
    return x >= 1 && x <= n && y >=1 && y <= m;
}

// 방향 : 하(0), 상(1), 우(2), 좌(3) 
void solve(int x, int y, int dir) {
    
    while(1) {
        if(!e(x, y)) break;
        if(ar[x][y] == 1) {
            if(dir == 0) dir = 3;
            else if(dir == 1) dir = 2;
            else if(dir == 2) dir = 1;
            else if(dir == 3) dir = 0;
        } 
        x = x + dx[dir];
        y = y + dy[dir];
    }
    cout << num[x][y] << " ";
}


int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cin >> ar[i][j];
        }
    }
    int mx = (2*n + 2*m);
    for(int i=1; i<=mx; i++) {
        if(i >= 1 && i <= n) {
            num[i][0] = i;
        }
        else if(i > n && i<=(n+m)) {
            int pos = i - n;
            num[n+1][pos] = i;
        }
        else if(i>(n+m) && i<=(n+m+n)) {
            int ref = (n+m+n);
            int pos = ref - i + 1;
            num[pos][m+1] = i;
        }
        else if(i>(n+m+n) && i<=mx) {
            int pos = mx - i + 1;
            num[0][pos] = i;
        }
    }

    for(int i=1; i<=mx; i++) {
        if(i >= 1 && i <= n) {
            num[i][0] = i;
            solve(i, 1, 2);
        }
        else if(i > n && i<=(n+m)) {
            int pos = i - n;
            num[n+1][pos] = i;
            solve(n, pos, 1);
        }
        else if(i>(n+m) && i<=(n+m+n)) {
            int ref = (n+m+n);
            int pos = ref - i + 1;
            num[pos][m+1] = i;
            solve(pos, m, 3);
        }
        else if(i>(n+m+n) && i<=mx) {
            int pos = mx - i + 1;
            num[0][pos] = i;
            solve(1, pos, 0);
        }
    }
}