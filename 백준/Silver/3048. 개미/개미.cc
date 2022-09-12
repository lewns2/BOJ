#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9


int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m; cin >> n >> m;
    string N1, N2; cin >> N1 >> N2;
    char ans[n+m];
    int dir[n+m];

    for(int i=0; i<n; i++) {
        ans[n-i-1] = N1[i];
        dir[n-i-1] = -1;
    }
    for(int i=0; i<m; i++) {
        ans[n+i] = N2[i];
        dir[n+i] = 1;
    }
    int t; cin >> t;
    while(t--) {
        for(int i=0; i<n+m-1; i++) {
            if(i <= n && dir[i] == 1 && dir[i+1] == -1) continue;
            if(dir[i] != dir[i+1]) {
                swap(ans[i], ans[i+1]);
                swap(dir[i], dir[i+1]);
                i++;
            }
        }
    }
    for(int i=0; i<n+m; i++) cout << ans[i];
}