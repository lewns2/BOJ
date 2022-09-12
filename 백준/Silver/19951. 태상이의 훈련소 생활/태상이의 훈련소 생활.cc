#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9


const int mxN = 1e5+10;
int n, m;
int ar[mxN], pref[mxN];

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i=1; i<=n; i++) cin >> ar[i];
    while(m--) {
        int a, b, c; cin >> a >> b >> c;
        pref[a] += c;
        pref[b+1] -= c;
    }
    for(int i=1; i<=n; i++) {
        pref[i] += pref[i-1];
    }
    for(int i=1; i<=n; i++) {
        cout << ar[i] + pref[i] << " ";
    }

}