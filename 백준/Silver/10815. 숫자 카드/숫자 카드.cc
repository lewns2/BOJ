#include<bits/stdc++.h>
using namespace std;

const int mxN=5e5;
int n, a[mxN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> a[i];
	}
	sort(a, a+n);
	
	int m;
	cin >> m;
	for(int i=0; i<m; i++) {
		int x;
		cin >> x;
		if(binary_search(a, a+n, x)) {
			cout << 1 << " ";
		}
		else {
			cout << 0 << " ";
		}
	}
}