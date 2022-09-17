#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9


int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        int l = 0, r = s.size()-1;
        
        if(s.size() == 1) {
            cout << 0 << "\n";
            continue;
        }

        bool ok = true;
        while(l <= r) {
            if(s[l] != s[r]) {
                ok = false;
                break;
            }
            l++, r--;
        }
        if(ok) cout << 0 << "\n";
        else if(s[s.size()-1] != '0') cout << 0 << "\n";
        else cout << 1 << "\n";
    }    
}
