#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9

vector<int> get_pi(string s) {
    int n = s.size();
    vector<int> pi(n);
    pi[0] = 0;
    for(int i=1, j=0; i<n; i++) {
        while(j && s[i] ^ s[j]) {
            j = pi[j-1];
        }
        if(s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}

int kmp(string s, string p) {
    int ans = 0;
    int n = s.size(), m = p.size();
    vector<int> pi = get_pi(p);

    for(int i=0, j=0; i<n; i++) {
        while(j && s[i] ^ p[j]) {
            j = pi[j-1];
        }
        if(s[i] == p[j]) {
            if(j == m - 1) {
                ans++;
                j = pi[j];
            }
            else j++;
        }
    }
    return ans;
}

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m; cin >> n >> m;
    string s; cin >> s;
    string p = "";
    for(int i=0; i<n*2+1; i++) {
       if(i%2) p += 'O';
       else p += 'I';
    }

    cout << kmp(s, p);

} 