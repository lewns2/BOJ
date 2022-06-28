#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define INFL 1e18
#define INF 1e9



int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
    int t; cin >> t;
    
    while(t--) {
        cin.ignore();
        string s;
        getline(cin, s);
        string ans = "god";
        bool flag = 0;
        for(int i=0; i<s.size(); i++) {
            if(flag && s[i] != ' ') {
                ans += s[i];
            }
            if(s[i] == ' ' && !flag) {
                flag = 1;
            }
        }
        cout << ans << "\n";

    }
}
