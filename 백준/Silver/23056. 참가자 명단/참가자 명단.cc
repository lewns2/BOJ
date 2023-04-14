#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1e9

const int mxN = 11, mxM = 11;
int n, m;
vector<string> W[11], B[11];

bool cmp(string a, string b) {
    if(a.size() != b.size()) {
        return a.size() < b.size();
    }

    return a < b;
}

int main () {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    int mx = 0;
    while(1) {
        int x; string s; cin >> x >> s;
        if(x == 0 && s == "0") break;
        mx = max(mx, x);
        if(x % 2 == 1) {
            if(B[x].size() >= m) continue;
            B[x].push_back(s);
        }
        else if(x % 2 == 0) {
            if(W[x].size() >= m) continue;
            W[x].push_back(s);
        }
    }

    for(int i=1; i<=mx; i+=2) {
        if(B[i].size() == 0) continue;
        sort(B[i].begin(), B[i].end(), cmp);
        for(int j=0; j<B[i].size(); j++) {
            cout << i << " " << B[i][j] << "\n";
        }
    }
    for(int i=2; i<=mx; i+=2) {
        if(W[i].size() == 0) continue;
        sort(W[i].begin(), W[i].end(), cmp);
        for(int j=0; j<W[i].size(); j++) {
            cout << i << " " << W[i][j] << "\n";
        }
    }
}
