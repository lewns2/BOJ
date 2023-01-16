#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define INF 1e9


int cnt[30];
int digit[10] = {0, 2, 4, 6, 8, 1, 3, 5, 7, 9};
// char order[100] = {Z, W, O, X, H, O, H, F, V, E};
string order[100] = {"ZERO", "TWO", "FOUR", "SIX", "EIGHT", "ONE", "THREE", "FIVE", "SEVEN", "NINE"};

int solve(string s) {
    int x = 1e9;

    for(int i=0; i<s.size(); i++) {
        x = min(x, cnt[s[i] - 'A']);
    }

    for(int i=0; i<s.size(); i++) {
        cnt[s[i] - 'A'] -= x;
    }

    return x;
}

int main() {
    int t; cin >> t;
    for(int tc=1; tc<=t; tc++) {
        string s; cin >> s;

        memset(cnt, 0, sizeof(cnt)); 
        for(int i=0; i<s.size(); i++) {
            int x = s[i] - 'A';
            cnt[x]++;
        }

        vector<int> res;

        for(int i=0; i<10; i++) {
            int x = solve(order[i]);
            for(int j=0; j<x; j++) {
                res.push_back(digit[i]);
            }
        }

        sort(res.begin(), res.end());
        
        string ans = "";
        for(auto x : res) {
            ans += (x + '0');
        }

        cout << "Case #" << tc << ": " << ans << "\n"; 
    }    
} 
