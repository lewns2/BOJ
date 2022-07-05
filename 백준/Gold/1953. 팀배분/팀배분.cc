#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define INFL 1e18
#define INF 1e9

const int mxN = 110;
int n;
vector<int> arr[mxN];
int vis[mxN];

void dfs(int v, int pos = 0) {
    vis[v] = pos;

    for(auto next : arr[v]) {
        if(vis[next] < 0) {
            dfs(next, pos^1);
        }
        else {
            if(vis[next] == pos) {
                return;
            }
        }
    }
}

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    for(int i=1; i<=n; i++) {
        int x; cin >> x;
        for(int j=0; j<x; j++) {
            int a; cin >> a;
            arr[i].push_back(a);
            arr[a].push_back(i);
        }
    }

    memset(vis, -1, sizeof(vis));

    for(int i=1; i<=n; i++) {
        if(vis[i] < 0) {
            dfs(i);
        }
    }

    vector<int> A, B;
    for(int i=1; i<=n; i++) {
        if(vis[i]) {
            A.push_back(i);
        }
        else if(vis[i] == 0) {
            B.push_back(i);
        }
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    cout << A.size() << "\n";
    for(auto x : A) {
        cout << x << " ";
    } cout << "\n";
    cout << B.size() << "\n";
    for(auto x : B) {
        cout << x << " ";
    }
}