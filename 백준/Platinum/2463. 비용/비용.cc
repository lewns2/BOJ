#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define INFL 1e18
#define INF 1e9

const int mxN = 1e5+10, MOD = 1e9;
int n, m;
vector<pair<int, pair<int, int>>> arr;
ll par[mxN], ds[mxN];

bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
    return a.first > b.first;
}

int find(int x) {
    if(par[x] == x) return x;
    
    return par[x] = find(par[x]);
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    if(a < b) swap(a, b);
    par[a] = b;
    ds[b] += ds[a];
    ds[a] = 1;
}

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
    cin >> n >> m;

    for(int i=1; i<=n; i++) {
        par[i] = i;
        ds[i] = 1;
    }

    ll tot = 0;
    for(int i=0; i<m; i++) {
        int fr, to, val; cin >> fr >> to >> val;
        arr.push_back({val, {fr, to}});
        tot += val;
    }

    sort(arr.begin(), arr.end(), cmp);

    ll ans = 0;
    for(int i=0; i<arr.size(); i++) {
        int c = arr[i].first;
        int s = arr[i].second.first;
        int e = arr[i].second.second;
        if(find(s) != find(e)) {
            ans += ((ds[par[s]] * ds[par[e]])%MOD * tot) % MOD;
            ans %= MOD;
            merge(s, e);
        }
        tot -= c;
    }
    cout << ans;
}