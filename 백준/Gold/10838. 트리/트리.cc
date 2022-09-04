#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9

const int mxN = 1e5+10;
int n, k;
int par[mxN], color[mxN], lca[mxN];

int getlca(int a, int b) {
    vector<bool> vis(n, false);
    int cnt = 0;
    while(a && cnt < 1000) {
        vis[a] = true;
        a = par[a];
        cnt++;
    }
    cnt = 0;
    while(b && cnt < 1000) {
        if(vis[b]) break;
        b = par[b];
        cnt++;
    }
    return b;
}

void paint(int a, int b, int c) {
    int x = getlca(a, b);
    // cout << "lca : " << x << "\n";
    while(a != x) {
        color[a] = c;
        a = par[a];
    }
    while(b != x) {
        color[b] = c;
        b = par[b];
    }
}

int count(int a, int b) {
    int x = getlca(a, b);
    set<int> st;
    st.clear();
    while(a != x) {
        st.insert(color[a]);
        a = par[a];
    }
    while(b != x) {
        st.insert(color[b]);
        b = par[b];
    }
    return (int)st.size();
}

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    for(int i=1; i<n; i++) par[i] = 0;
    
    while(k--) {
        int r; cin >> r;
        if(r == 1) {
            int a, b, c; cin >> a >> b >> c;
            paint(a, b, c);
        }
        else if(r == 2) {
            int a, b; cin >> a >> b;
            par[a] = b;
            // for(int i=0; i<n; i++) {
            //     if(i == a || par[i] == a) par[i] = b;
            // }
        }
        else if(r == 3) {
            int a, b; cin >> a >> b;
            cout << count(a,b) << "\n";
        }
    }
}