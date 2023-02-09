#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1e9

const int mxN = 5e5+10;
vector<string> ar;

bool isP(string s) {
    int l = 0;
    int r = s.size()-1;

    bool ok = true;
    while(l < r) {
        if(s[l] != s[r]) {
            ok = false;
            break;
        }
        l++;
        r--;
    }
    return ok;
}

int main () {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string s; cin >> s;

    bool flag = true;
    
    int c = s[0];
    for(int i=1; i<s.size(); i++) {
        if(s[0] != s[i]) {
            flag = false;
            break;
        }
    }
    
    if(isP(s)) {
        if(!flag) {
            cout << s.size()-1;
        }
        else {
            cout << -1;
        }
    }
    
     else {
        cout << s.size();
    }
}

/*
S가 팰린드롬O && 한글자가 아니다? -> ans = s.size()-1
S가 팰린드롬O && 한글자로 구성? -> ans = -1
S가 팰린드롬 X -> ans = s.size()
*/