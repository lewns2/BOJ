#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define INF 1e9

const int mxN = 1e5+10;
int n, ar[2][mxN];
int dp[mxN][3];

int solve(int x, int y, int status) {
    if(y > n-1) return 0;

    if(dp[y][status] != -1) return dp[y][status];
    dp[y][status] = 0;

    int res = solve(x, y+1, 0);
    if(status != 1) {
        res = max(res, solve(x, y+1, 1) + ar[0][y]);
    }
    if(status != 2) {
        res = max(res, solve(x, y+1, 2) + ar[1][y]);
    }

    dp[y][status] = res;

    return dp[y][status];

}

int main() {
    int t; cin >> t;
    while(t--) {
        cin >> n;
        for(int i=0; i<2; i++) {
            for(int j=0; j<n; j++) {
                cin >> ar[i][j];
            }
        }
        memset(dp, -1, sizeof(dp));

        cout << solve(0, 0, 0) << "\n";

    }
} 