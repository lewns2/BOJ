#include <bits/stdc++.h>
using namespace std;

int n;

bool cmp(int a, int b) {
	return a > b;
}
int main() {
	while(true) {
		cin >> n;
		if(n==0) return 0;
		vector<int> v(n);
		v.clear();
		for(int i=0; i<n; i++) {
			int a;
			cin >> a;
			v[i] = a;
		}
	//	for(auto x : v) {
	//		cout << x << " ";
	//	}
	
		int rr=6;
		vector<int> r;
		
		for(int i=0; i<rr; i++) {
			r.push_back(1);
		}
		for(int i=0; i<n-rr; i++) {
			r.push_back(0);
		}
	
		
		do{
			for(int i=0; i<n; i++) {
				if(r[i]==1) {
					cout << v[i] << " ";
				}
			}
			cout << "\n";
		}
		while(next_permutation(r.begin(), r.end(),cmp));		
		cout << "\n";
	}
	
}