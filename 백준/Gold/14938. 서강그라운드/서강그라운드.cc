#include<bits/stdc++.h>
using namespace std;

#define INF 1e9

const int mxN=101;
int n, m, r, item[mxN], a, b, l;
vector<pair<int, int>> arr[mxN];
int dist[mxN];

int solve(int cost, int start) {
	
	int ans=0;
	
	fill(dist, dist+n+1, INF);
	dist[start]=0;
	
	priority_queue<pair<int, int>> pq;
	pq.push({dist[start], start});
	
	while(pq.size()) {
		int cost = -pq.top().first;
		int now = pq.top().second;
		pq.pop();
		
		
		for(int i=0; i<arr[now].size(); i++) {
			int next = arr[now][i].first;
			int nextcost = arr[now][i].second;
			
			if(dist[next] > dist[now] + nextcost) {
				dist[next] = dist[now] + nextcost;
				pq.push({-dist[next], next});
			}
		}
	}
	for(int i=1; i<=n; i++) {
		if(dist[i] <= m) {
			ans += item[i];
		}
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
 	cin.tie(0);
 	cout.tie(0);
 	
	cin >> n >> m >> r;
	for(int i=1; i<=n; i++) {
		cin >> item[i];
	}
	for(int i=0; i<r; i++) {
		cin >> a >> b >> l;
		arr[a].push_back({b, l});
		arr[b].push_back({a, l});
	}
	
	int result=0;
	for(int i=1; i<=n; i++) {
		result = max(result, solve(0, i));
	}
	cout << result;
}