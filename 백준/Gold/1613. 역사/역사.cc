#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9

const int mxN = 440;
int n, k;
int ar[mxN][mxN];

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    while(k--) {
        int a, b; cin >> a >> b;
        ar[a][b] = -1;
        ar[b][a] = 1;
    }
    int s; cin >> s;
    
    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(ar[i][j] != 0) continue;
                if(ar[i][k] == 1 && ar[k][j] == 1) ar[i][j] = 1;
                else if(ar[i][k] == -1 && ar[k][j] == -1) ar[i][j] = -1;
            }
        }
    }
    
    while(s--) {
        int a, b; cin >> a >> b;
        cout << ar[a][b] << "\n";
    }
}
