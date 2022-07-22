#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9


int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string s; cin >> s;
    vector<ll> num;

    int tmp = 1;
    for(int i=0; i<s.size(); i++) {
        int x = s[i] - '0';
        tmp *= x;
        num.push_back(tmp);
    }
    
    int ans = 1, flag = 0;
    for(int i=s.size()-1; i>-1; i--) {
        int x = s[i]-'0';
        ans *= x;
        
        if(ans == num[i-1]) {
            flag = 1;
            break;
        }
    }
    if(flag) cout << "YES";
    else cout << "NO";


} 