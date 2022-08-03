#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9

bool ok = false;

vector<int> get_pi(string s) {
    int n = s.size();
    vector<int> pi(n+1);

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

void kmp(string s, string p) {
    int n = s.size(), m  = p.size();
    vector<int> pi = get_pi(p);
    
    for(int i=0, j=0; i<n; i++) {
        while(j && s[i] ^ p[j]) {
            j = pi[j-1];
        }
        if(s[i] == p[j]) {
            if(j == m-1) {
                ok = true;
                j = pi[j];
                return;
            }
            else j++;
        }
    }
}

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string s, p;
    cin >> s >> p;
    kmp(s, p);
    cout << ok;
} 