#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define INF 1e9

const int mxN = 101;
int n, x;
int ar[mxN];

int main() {
    cin >> n >> x;
    for(int i=0; i<n; i++) {
        cin >> ar[i];
    }

    int ans = -1;
    while(1) {
        bool ok = true;
        for(int i=0; i<n; i++) {
            if(x > ar[i]) {
                ok = false;
                ans = i+1;
                break;
            }
            if(!ok) break;
            x++;
        }
        if(!ok) break;
    }
    cout << ans;
    
} 
