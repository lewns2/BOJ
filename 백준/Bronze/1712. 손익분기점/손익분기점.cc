#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll a, b, c; cin >> a >> b >> c;
    ll x = c - b;
    if(x <= 0) cout << -1;
    else cout << a/x+1;
} 
