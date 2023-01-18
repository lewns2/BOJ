#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define INF 1e9

int solve(string S) {

    int cnt = 0;

    for(int i=0; i<S.size(); i++) {
        if(S[i] == 'f') {
            if(i+2 > S.size() - 1) continue;

            if(S[i+1] == 'o' && S[i+2] == 'r') {
                cnt++;
            }
        }
        else if(S[i] == 'w') {
            if(i+4 > S.size() - 1) continue;

            if(S[i+1] == 'h' && S[i+2] == 'i' && S[i+3] == 'l' && S[i+4] == 'e') {
                cnt++;
            }
        }
    }
    
    return cnt;
}

int main() {
    int n; cin >> n;
    int ans = 0;
    while(n--) {
        string s; cin >> s;
        ans = max(ans, solve(s));
    }
    cout << ans;
} 
