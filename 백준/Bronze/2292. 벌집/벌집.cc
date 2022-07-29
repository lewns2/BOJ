#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9


int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll x; cin >> x;

    int n = 0;
    while(1) {
        ll ref = 6 * (n * (n+1) / 2) + 1;
        if(ref < x) n++;
        else break;
    }
    cout << n+1;

}
