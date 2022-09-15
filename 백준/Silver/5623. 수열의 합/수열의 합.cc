#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9


const int mxN = 1e3+10;
int n, ar[mxN][mxN];

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    
    ll ans[n];
    ll tot = 0;
    for(int i=0; i<n; i++) {
        ll tmp = 0;
        for(int j=0; j<n; j++) {
            cin >> ar[i][j];
            tmp += ar[i][j];
            tot += ar[i][j];
        }
        ans[i] = tmp;
    }

    tot = tot / (2*n - 2);
    if(n == 2) {
        cout << tot / 2 << " " << tot / 2;
    }
    else {
        for(int i=0; i<n; i++) {
            cout << (ans[i] - tot) / (n-2) << " ";
        }
    }

}
