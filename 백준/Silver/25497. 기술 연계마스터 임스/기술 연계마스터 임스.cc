#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    string s; cin >> s;

    stack<char> st1, st2;
    bool ok = true;
    int ans = 0;
    for(int i=0; i<n; i++) {
        if(s[i] - '0' >= 0 && s[i] - '0' <= 9) {
            ans++;
        }
        if(s[i] == 'S') {
            st1.push(s[i]);
        }
        if(s[i] == 'K') {
            if(st1.size() != 0) {
                st1.pop();
                ans++;
            }
            else ok = false;
        }
        if(s[i] == 'L') {
            st2.push(s[i]);
        }
        if(s[i] == 'R') {
            if(st2.size() != 0) {
                st2.pop();
                ans++;
            }
            else ok = false;
        }

        if(!ok) break;
    }
    cout << ans;
}