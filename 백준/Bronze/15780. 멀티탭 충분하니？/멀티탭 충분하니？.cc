#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define INFL 1e18
#define INF 1e9


int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
    int n, k; cin >> n >> k;
    int ans = 0;
    for(int i=0; i<k; i++) {
        int a; cin >> a;
        ans += (a/2);
        if(a % 2) ans++;
    }
    if(ans >= n) cout << "YES";
    else cout << "NO";
}