#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9

vector<int> space;

vector<int> get_pi(string s) {
    int n = s.size();
    vector<int> pi(n);
    pi[0] = 0;
    for(int i=1, j=0; i<n; i++) {
        while(j && s[i] ^ s[j]) {
            j = pi[j-1];
        }
        if(s[i] == s[j]) {
            j++;
        }
        pi[i] = j;
    }
    return pi;
}

int kmp(string s, string p) {
    int n = s.size(), m = p.size();
    int ans = 0;
    vector<int> pi = get_pi(p);

    for(int i=0, j=0; i<n; i++) {
        while(j != 0 && s[i] ^ p[j]) {
            j = pi[j-1];
        }
        if(s[i] == p[j]) {
            if(j == m-1) {
                ans++;
                j = pi[j];
                int idx = i - m + 2;
                space.push_back(idx);
            }
            else j++;
        }
    }
    return ans;
}

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string s, p;
    getline(cin, s);
    getline(cin, p);

    cout << kmp(s, p) << "\n";
    for(auto x : space) {
        cout << x << " ";
    }

}