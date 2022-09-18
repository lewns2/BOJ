#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9


bool solveL(string S, int left, int right) {
    while(left <= right) {
        if(S[left] != S[right]) {
            return false;
        } 
        left++, right--;
    }
    return true;
}

bool solveR(string S, int left, int right) {
    while(left <= right) {
        if(S[left] != S[right]) {
            return false;
        } 
        left++, right--;
    }
    return true;
}

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        bool ok = true, isOk = false;
        int l = 0, r = s.size()-1;
        while(l <= r) {
            if(s[l] != s[r]) {
                if(solveL(s, l+1, r)) {
                    ok = false;
                    isOk = true;
                }
                else if(solveR(s, l, r-1)) {
                    ok = false;
                    isOk = true;
                }
                else {
                    ok = false;
                }
                break;
                
            }
            l++, r--;
        }
        if(ok) cout << 0 << "\n";
        else if(!ok && isOk) cout << 1 << "\n";
        else cout << 2 << "\n";
    } 
}