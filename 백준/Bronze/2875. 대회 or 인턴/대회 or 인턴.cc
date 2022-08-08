#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9


int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m, k; cin >> n >> m >> k;
    int tot = 0, mod = 0;

    if(m*2 < n) {
        tot = m;
        mod = n - (m*2);
    }
    else if(m*2 > n){
        tot = n/2;
        mod = m - tot;
    }
    else if(m*2 == n) {
        tot = n/2;
        mod = 0;
    }

    if(mod - k >= 0) {
        cout << tot;
    }

    else {
        int x = (k-mod) / 3;
        if((k-mod)%3 != 0) x++;
        cout << tot - x;
    }
} 