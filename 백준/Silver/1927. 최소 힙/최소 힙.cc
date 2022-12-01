#include<bits/stdc++.h>
using namespace std;

const int mxN=1e5;
int n;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);	
	cout.tie(NULL);
	cin >> n;
	
	while(n--) {
		int a;
		cin >> a;
		if(a==0) {
			if(pq.empty()) {
				cout << 0 << "\n";
			}
			else {
				cout << pq.top() << "\n";
				pq.pop();		
			}
		}
		if(a!=0) {
			pq.push(a);
		}
	}
}