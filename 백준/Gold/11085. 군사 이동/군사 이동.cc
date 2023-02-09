#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1e9

const int mxN = 1e3+10, mxM = 5e4+10;
int n, m, s, e;
vector<pair<int, pair<int, int>>> ar;
int par[mxN];

bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
    return a.first > b.first;
}

int find(int x) {
    if(par[x] == x) return x;

    return par[x] = find(par[x]);
}

bool merge(int a, int b) {
    a = find(a), b = find(b);
    if(a == b) return true;
    
    if(a > b) swap(a, b);
    par[a] = b;
    return false;
}

int main () {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    cin >> s >> e;
    for(int i=0; i<m; i++) {
        int x, y, w; cin >> x >> y >> w;
        ar.push_back({w, {x, y}});
    }
    sort(ar.begin(), ar.end(), cmp);

    for(int i=0; i<n; i++) {
        par[i] = i;
    }

    int ans = INF;
    for(int i=0; i<ar.size(); i++) {
        int c = ar[i].first;
        int x = ar[i].second.first;
        int y = ar[i].second.second;

        if(!merge(x, y)) {
            ans = min(ans, c);
        }

        if(find(s) == find(e)) break;
    }

    cout << ans;

}