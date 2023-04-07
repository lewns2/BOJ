#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1e9



int main () {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    int ans = 0;
    for(int i=0; i<5; i++) {
        int x; cin >> x;
        if(x == t) ans++;
    }
    cout << ans;

}