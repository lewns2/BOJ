#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9

const int mxN = 550;
int n, m;
int ar[mxN][mxN];

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    while(m--) {
        int a, b; cin >> a >> b;
        ar[a][b] = 1;
        ar[b][a] = -1;
    }
    
    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(ar[i][k] == 1 && ar[k][j] == 1) ar[i][j] = 1;
                if(ar[i][k] == -1 && ar[k][j] == -1) ar[i][j] = -1;
            }
        }
    }

    int cnt = 0;
    for(int i=1; i<=n; i++) {
        bool ok = true;
        for(int j=1; j<=n; j++) {
            if(i == j) continue;
            if(ar[i][j] == 0) {
                ok = false;
                break;
            }
        }
        if(ok) cnt++;
    }
    cout << cnt;

} 
