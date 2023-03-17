#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9


int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    string s; cin >> s;

    int len = n*2+1;

    int pos = 0, ans = 0;

    while(pos + (n*2) < m) {
        
        bool ok = true;
        for(int i=pos; i<pos+len; i++) {
            int x = i - pos;            
            if(x % 2 && s[i] == 'I') {
                ok = false;
                break;
            }    
            else if(x % 2 == 0 && s[i] == 'O') {
                ok = false;
                break;
            }
        }
        if(ok) ans++;
        pos++;
    }
    
    cout << ans;
} 