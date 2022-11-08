#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define INF 1e9

const int mxN = 1e5+10;
int n, m;
vector<pair<int, int>> ar;
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
    
    int ans = 0;
    
    for(int i=0; i<m; i++) {
        int a, b; cin >> a >> b;
        ar.push_back({a, b});
        if(!merge(a, b)) ans++;
    }
    set<int> st;
    for(int i=1; i<=n; i++) {
        if(find(i) == i) ans++;
    }

    cout << ans - 1;
} 