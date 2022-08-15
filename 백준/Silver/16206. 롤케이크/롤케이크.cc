#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9



int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m; cin >> n >> m;
    vector<int> ar, c;

    int ans = 0;
    for(int i=0; i<n; i++) {
        int a; cin >> a;
        if(a == 10) ans++;
        else if(a % 10 == 0) ar.push_back(a);
        else c.push_back(a);
    }

    sort(ar.begin(), ar.end());
    for(int i=0; i<c.size(); i++) {
        ar.push_back(c[i]);
    }
    
    for(int i=0; i<ar.size(); i++) {
        int x = ar[i] / 10;
        if(ar[i] % 10 == 0) {
            if(m >= x-1) {
                m -= (x-1);
                ans += x;
            }
            else {
                ans += m;
                m = 0;
            }
        }
        else {
            if(m >= x) {
                m -= x;
                ans += x;
            }
            else {
                ans += m;
                m = 0;
            }
        }
        if(m == 0) break;
    }
    cout << ans;

}