#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9



int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    int ar[26]={0, };

    for(int i=0; i<n; i++) {
        string s; cin >> s;
        int x = s[0] - 'a';
        ar[x]++;
    }

    bool ok = false;
    for(int i=0; i<26; i++) {
        if(ar[i] >= 5) {
            ok = true;
            char x = i + 'a';
            cout << x;
        }
    }
    if(!ok) cout << "PREDAJA";
    
} 