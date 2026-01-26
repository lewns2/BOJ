#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define INFL 1e18
#define INF 1e9

const int mxN = 1e5+10;
int n, m, t;
vector<int> arr[mxN], rarr[mxN];
int vis[mxN];
set<int> s1, s2;

void dfs(int x) {
    vis[x] = 1;
   
    s1.insert(x);
    
    for(int i=0; i<arr[x].size(); i++) {
        int nxt = arr[x][i];
        if(!vis[nxt]) {
            dfs(nxt);
        }
    } 
}

void rdfs(int x) {
    vis[x] = 1;
    s2.insert(x);

    for(int i=0; i<rarr[x].size(); i++) {
        int nxt = rarr[x][i];
        if(!vis[nxt]) {
            rdfs(nxt);
        }
    }
}

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int a, b; cin >> a >> b;
        arr[a].push_back(b);
        rarr[b].push_back(a);

    }

    memset(vis, 0, sizeof(vis));
    dfs(1);
    memset(vis, 0, sizeof(vis));
    rdfs(n);

    s1.insert(n+10);
    s2.insert(n+10);

    cin >> t;
    while(t--) {
        int x; cin >> x;
        
        auto iter = s1.find(x);
        auto iter2 = s2.find(x);

        if(iter != s1.end() && iter2 != s2.end()) {
            cout << "Defend the CTP";
        } else {
            cout << "Destroyed the CTP";
        }       
        cout << "\n";
    }
}
