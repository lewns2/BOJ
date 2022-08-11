#include<bits/stdc++.h>
using namespace std;


#define ll long long

const int mxN=200;
int n, m;
ll a[mxN+1][mxN+1], dp[mxN+1][mxN+1];

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	ll ans=-1e4;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			cin >> a[i][j];
			dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + a[i][j];
		} 
	}
	for(int x1=1; x1<=n; x1++) {
		for(int y1=1; y1<=n; y1++) {
			for(int x2=x1; x2<=n; x2++) {
				for(int y2=y1; y2<=n; y2++) {
					ans = max(ans, dp[x2][y2] - dp[x1-1][y2] -dp[x2][y1-1] + dp[x1-1][y1-1]);
				}
			}
		}
	}
	cout << ans;
}