#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while(t--) {
        string s, p; cin >> s >> p;
        int n = s.size(), m = p.size();

        int ans = 0;
        int i = 0;
        while(i < n) {
            string x = s.substr(i, m);
            if(x == p) {
                ans++;
                i += (m-1);
            }
            i++;
        }
        cout << n - (ans * m) + ans << "\n";
    }    
}