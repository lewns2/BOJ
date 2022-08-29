#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9

const int mxN = 303;
int n, par[mxN];
vector<pair<int, pair<int, int>>> ar;

int find(int x) {
    if(par[x] == x) return x;
    return par[x] = find(par[x]);
}

bool merge(int a, int b) {
    a = find(a); b = find(b);
    if(a == b) return false;
    if(a < b) swap(a, b);
    par[a] = b;
    return true;
}

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i=0; i<=n; i++) {
        par[i] = i;
    }
    int cost[n+1];
    for(int i=0; i<n; i++) {
        cin >> cost[i];
        ar.push_back({cost[i], {n, i}});
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            int x; cin >> x;
            if(i == j) continue;
            ar.push_back({x, {i, j}});
        }
    }
    sort(ar.begin(), ar.end());
    
    int ans = 0;
    for(int i=0; i<ar.size(); i++) {
        int c = ar[i].first;
        int s = ar[i].second.first;
        int e = ar[i].second.second;
        if(merge(s, e)) {
            ans += c;
        }
    }
    cout << ans;
}