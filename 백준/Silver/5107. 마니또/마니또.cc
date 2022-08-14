#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9

const int mxN = 25;

struct DSU {
    int par[mxN];

    void init(int n) {
        for(int i=1; i<=n; i++) {
            par[i] = i;
        }
    }

    int find(int x) {
        if(x == par[x]) return x;
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

    set<int> st;
    int solve(int n) {
        st.clear();
        for(int i=1; i<=n; i++) {
            st.insert(par[i]);
        }
        return (int)st.size();
    }

} uf;

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int TC = 0;
    while(1) {
        TC++;
        int n; cin >> n;
        if(n == 0) break;

        uf.init(n);

        int cnt = 0;
        map<string, int> mp;

        for(int i=0; i<n; i++) {
            string a, b; cin >> a >> b;
            if(!mp[a]) mp[a] = ++cnt;
            if(!mp[b]) mp[b] = ++cnt;
            uf.merge(mp[a], mp[b]);
        }

        cout << TC << " " << uf.solve(n) << "\n";
    }
}