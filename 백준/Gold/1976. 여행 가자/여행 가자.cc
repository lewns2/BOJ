#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 2e18
#define INF 2e9

const int mxN = 201, mxM = 1001;
int n, m;
int a[mxN][mxN];
vector<int> arr[mxN];
int par[mxN];
int plan[mxN];

int find(int x) {
    if(par[x] == x) return x;

    return par[x] = find(par[x]);
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);

    if(a > b) {
        par[a] = b;
    }
    if(a < b) {
        par[b] = a;
    }
}

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    cin >> m;

    for(int i=1; i<=n; i++) {
        par[i] = i;
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> a[i][j];
            if(a[i][j]) {
                merge(i, j);
            }
        }
    }
    
    set<int> s;
    for(int i=0; i<m; i++) {
        int x; cin >> x;
        s.insert(par[x]);

    }

    if(s.size() == 1) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }

}
