#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9

bool ok = false;


int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string s; cin >> s;
    int l = 0, r = s.size() - 1;

    bool ok = true;
    while(l<r) {
        if(s[l] != s[r]) {
            ok = false;
            break;
        }
        l++; r--;
    }  
    cout << ok;
} 