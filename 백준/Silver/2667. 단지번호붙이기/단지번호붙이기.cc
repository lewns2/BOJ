#include<bits/stdc++.h>
using namespace std;

const int mxN=25;
int n;
string s[mxN];
vector<int> v;
int cnt;

bool e(int i, int j) {
	return i>=0 && i<n && j>=0 && j<n && s[i][j]=='1';
}

void dfs(int i, int j) {
	cnt++;
	s[i][j] = true;
	
	if(e(i-1, j)) {
		dfs(i-1, j);
	}
	if(e(i+1, j)) {
		dfs(i+1, j);
	}
	if(e(i, j-1)) {
		dfs(i, j-1);
	}
	if(e(i, j+1)) {
		dfs(i, j+1);
	}
	
}

int main() {
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> s[i];
	}
	int ans=0;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(e(i, j)) {
				cnt=0;
				dfs(i, j), ans++;
				v.push_back(cnt);
		
			}
			
		}
	}
	cout << ans << "\n";
	sort(v.begin(), v.end());
	for(auto x : v) {
		cout << x << "\n";
	}
}