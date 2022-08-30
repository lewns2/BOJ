#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9

const int mxN = 1e4+20;
int n, m;
vector<pair<int, pair<int, int>>> ar;

struct DSU {
    int par[mxN];
    void init(int n) {
        for(int i=0; i<=n; i++) {
            par[i] = i;
        }
    }

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
} uf;



bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
    return a.first > b.first;
}

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    uf.init(n);
    for(int i=0; i<m; i++) {
        int a, b, c; cin >> a >> b >> c;
        ar.push_back({c, {a, b}});
    }
    int fr, to; cin >> fr >> to;
    vector<int> ans;
    sort(ar.begin(), ar.end(), cmp);
    for(int i=0; i<ar.size(); i++) {
        int c = ar[i].first;
        int s = ar[i].second.first;
        int e = ar[i].second.second;
        if(uf.merge(s, e)) {
            ans.push_back(c);
        }
        if(uf.find(fr) == uf.find(to)) {
            cout << c;
            break;
        }
    }
}