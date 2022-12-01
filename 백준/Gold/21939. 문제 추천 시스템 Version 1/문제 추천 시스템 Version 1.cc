#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define INF 1e9

const int mxN = 1e5+10;
int n, m;
priority_queue<pair<int, int>> maxQ;
priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> minQ;
map<int, int> mp;

int main() {
	cin >> n;
	while(n--) {
		int num, level; cin >> num >> level;
		minQ.push({level, num});
		maxQ.push({level, num});
		mp[num] = level;
	}
	cin >> m;
	while(m--) {
		string x; cin >> x;
		if(x == "add") {
			int p, l; cin >> p >> l;
			minQ.push({l, p});
			maxQ.push({l, p});
			mp[p] = l;
		}
		else if(x == "recommend") {
			int a; cin >> a;
			if(a == 1) {
				while(mp[maxQ.top().second] != maxQ.top().first) maxQ.pop();
				cout << maxQ.top().second << "\n";
			}
			else if(a == -1) {
				while(mp[minQ.top().second] != minQ.top().first) minQ.pop();
				cout << minQ.top().second << "\n";
			}
		}
		else if(x == "solved") {
			int num; cin >> num;
			mp[num] = 0;
		}
	}
    
} 