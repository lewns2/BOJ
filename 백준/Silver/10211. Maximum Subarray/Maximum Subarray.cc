#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int ans=-1e4, msf=-1e4;
		for(int i=0; i<n; i++) {
			int a;
			cin >> a;
			msf = max(a, msf+a);
			ans = max(ans, msf);
		}
		cout << ans << "\n";
	}
}