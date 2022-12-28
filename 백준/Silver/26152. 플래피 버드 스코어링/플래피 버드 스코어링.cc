#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define INF 1e9

const int mxN = 250001;
int n;
ll h[mxN];

int main() {
	ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
	cin >> n;

	for(int i=0; i<n; i++) {
		cin >> h[i];
	}
	for(int i=0; i<n; i++) {
		int a; cin >> a;
		h[i] -= a;
	}

	for(int i=1; i<n; i++) {
		if(h[i-1] < h[i]) {
			h[i] = h[i-1];
		}
	}

	int q; cin >> q;
	while(q--) {
		ll x; cin>> x;

		if(x > h[0]) {
			cout << 0 << "\n";
			continue;
		}

		ll lo = 0, hi = n;
		while(lo+1 < hi) {
			ll mid = (lo + hi) / 2;
			if(h[mid] >= x) {
				lo = mid;
			}
			else {
				hi = mid;
			}
		}
		cout << hi << "\n";
	}
} 
