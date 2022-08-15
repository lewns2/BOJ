#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9

const int mxN = 1e3+5;
int n, m;

struct DSU {
    int par[mxN];

    void init(int n) {
        for(int i=1; i<=n; i++) {
            par[i] = i;
        }
    }

    int find(int x) {
        if(par[x] == x) return x;
        return par[x] = find(par[x]);
    }

    bool merge(int a, int b) {
        a = find(a);
        b = find(b);
        if(a == b) return false;
        if(a < b) swap(a, b);
        par[a] = b;
        return true;
    }


} uf;

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while(t--) {
        cin >> n >> m;
        
        uf.init(n);
        
        int ans = 0;
        for(int i=0; i<m; i++) {
            int a, b; cin >> a >> b;
            if(uf.merge(a, b)) {
                ans++; 
            }
        }
        cout << ans << "\n";
    }    
}