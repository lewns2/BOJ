#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int p, n; cin >> p >> n;
    int ar[n];
    for(int i=0; i<n; i++) {
        cin >> ar[i];
    }
    if(p == 200) {
        cout << 0;
    }
    else {
        sort(ar, ar+n);
        int ans = 0;
        for(int i=0; i<n; i++) {
            if(p + ar[i] < 200) {
                p += ar[i];
                ans++;
            }
        }
        cout << min(n, ans+1);
    }
}