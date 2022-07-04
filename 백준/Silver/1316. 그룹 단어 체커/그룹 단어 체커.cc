#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define INFL 1e18
#define INF 1e9

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;

    int ans = 0;
    for(int i=0; i<n; i++) {
        string s; cin >> s;
        
        map<char, int> mp;
        bool flag = 1; char x = s[0];
        mp[x] = 1;
        for(int j=1; j<s.size(); j++) {
            if(x == s[j]) continue;
            if(x != s[j]) {
                x = s[j];
                if(mp[x] == 1) {
                    flag = 0;
                    break;
                }
                else {
                    mp[x] = 1;
                }
            }
        }
        if(flag) ans++;
    }    
    cout << ans;
}