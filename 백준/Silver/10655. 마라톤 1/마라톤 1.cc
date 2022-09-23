#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9


const int mxN = 1e5+10;
int n;
vector<pair<int, int>> ar;
int dist[mxN]; // now-1 ~ now 거리

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++) {
        int x, y; cin >> x >> y;
        ar.push_back({x, y});
    }
    
    int tot = 0;
    for(int i=1; i<n; i++) {
        int tmp = (abs(ar[i-1].first - ar[i].first) + abs(ar[i-1].second - ar[i].second));
        dist[i] = tmp;
        tot += tmp;
    }

    int ans = -1;
    for(int i=1; i<n-1; i++) {
        int nd = (abs(ar[i-1].first - ar[i+1].first) + abs(ar[i-1].second - ar[i+1].second));
        int res = tot - dist[i] - dist[i+1] + nd;
        if(ans == -1) ans = res;
        else ans = min(ans, res);
    }
    cout << ans;
}
