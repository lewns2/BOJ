#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define INF 1e9

const int mxN = 1e5+10;
int n, m;
vector<pair<int, pair<int, int>>> ar;
int par[mxN];

int find(int x) {
    if(par[x] == x) return x;
    return par[x] = find(par[x]);
}

bool merge(int a, int b) {
    a = find(a), b = find(b);
    if(a == b) return false;
    if(a > b) swap(a, b);
    par[a] = b;

    return true;
}

int main() {
    cin >> n >> m;
    for(int i=1; i<=n; i++) par[i] = i;
    for(int i=0; i<m; i++) {
        int a, b, c; cin >> a >> b >> c;
        ar.push_back({c, {a, b}});
    }
    sort(ar.begin(), ar.end());
    
    int ans = 0, last = 0;
    for(int i=0; i<m; i++) {
        int x = ar[i].second.first;
        int y = ar[i].second.second;
        if(merge(x, y)) {
            last = ar[i].first;
            ans += last;
        }
    }
    cout << ans - last;

} 