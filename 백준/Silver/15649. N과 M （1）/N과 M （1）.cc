#include<bits/stdc++.h>
using namespace std;

const int mxN=9;
int n, m;
int a[mxN];
bool vis[mxN];

void recur(int cnt) {
	if(cnt == m) {
		for(int i=0; i<m; i++) {
			cout << a[i] << " ";
		} cout << "\n";
	}
	
	for(int i=1; i<=n; i++) {
		if(!vis[i]) {
			vis[i] = true;
			a[cnt] = i;
			recur(cnt+1);
			vis[i] = false;
		}
	}
}

int main() {
	cin >> n >> m;
	recur(0);
}