#include<bits/stdc++.h>
using namespace std;

const int mxN=20, dx[4]={1, -1, 0, 0}, dy[4]={0, 0, 1, -1};
int n, a[mxN][mxN], si, sj;
int sizing=2, cnt=0;
vector<pair<int, pair<int, int>>> eat;
bool vis[mxN][mxN];
int dist[mxN][mxN];


void bfs(int i, int j) {
	a[i][j] = 0;
	queue<pair<int, int>> q;
	q.push({i, j});
	
	vis[i][j] = true;
	dist[i][j] = 0;
	
	while(q.size()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		
		for(int k=0; k<4; k++) {
			int nx = x+dx[k];
			int ny = y+dy[k];
			
			if(nx<0 || nx>=n || ny<0 || ny>=n) continue;
			
			// 방문처리? 값 바꾸기?, eat에 계속 담김. 
			if(!vis[nx][ny] && a[nx][ny] <= sizing) {
				if(a[nx][ny] < sizing && a[nx][ny] != 0) {
					vis[nx][ny] = true;
					dist[nx][ny] = dist[x][y] + 1;
					eat.push_back({dist[nx][ny], {nx, ny}});
					q.push({nx, ny});
				}
				
				if(a[nx][ny] == sizing || a[nx][ny] == 0) {
					vis[nx][ny] = true;
					dist[nx][ny] = dist[x][y] + 1;
					q.push({nx, ny});
				}
			}
		}
	}
	return;
}

int main() {
	cin >> n;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cin >> a[i][j];
			if(a[i][j] == 9) {
				si = i;
				sj = j;
			}
		}
	}
	int ans=0;
	while(1) {
		memset(vis, 0, sizeof(vis));
		memset(dist, 0, sizeof(dist));
		bfs(si, sj);
//		cout << "시작좌표: " << si << " " << sj << "\n";
//		cout << "거리" << ans << "\n";
//		for(int i=0; i<n; i++) {
//			for(int j=0; j<n; j++) {
//				cout << a[i][j] << " ";
//			}
//			cout << "\n";
//		}
		if(eat.empty()) break;
		
		sort(eat.begin(), eat.end());
		ans += eat[0].first;
		si = eat[0].second.first;
		sj = eat[0].second.second;
		cnt++;
		
		if(sizing == cnt) {
			sizing++;
			cnt = 0;
		}
		eat.clear();
	}
	cout << ans;
	
}