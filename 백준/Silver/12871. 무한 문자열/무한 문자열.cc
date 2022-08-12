#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    string s, p; cin >> s >> p;

    string a = s;
    string b = p;
    
    int S = s.size(), P = p.size();
    for(int i=0; i<S-1; i++) {
        p += b;
    }
    for(int i=0; i<P-1; i++) {
        s += a;
    }
    if(s == p) cout << 1;
    else cout << 0;
    
}