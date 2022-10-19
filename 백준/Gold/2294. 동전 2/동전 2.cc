#include <bits/stdc++.h>
using namespace std;

const int mxN=100, mxK=1e5; 
int n, x;
int c[mxN+1], dp[mxK+1];

int main() {
	cin >> n >> x;
	for(int i=0; i<n; i++) {
		cin >> c[i];
	}
	
	for(int i=1; i<=x; i++) {
		dp[i] = 1e9;
	}
	
	for(int j=0; j<n; j++) {
		for(int i=1; i<=x; i++) {
			if(i>=c[j]) {
				dp[i] = min(dp[i], dp[i-c[j]]+1);
			}
		}
	}
	if(dp[x]==1e9) {
		cout << -1 << endl;
	}
	else {
	cout << dp[x] << endl;	
	}
	
}