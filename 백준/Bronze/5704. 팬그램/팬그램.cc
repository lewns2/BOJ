#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1e9


int main () {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    vector<int> chk(27);

    while(1) {
        string s; getline(cin, s);
        if(s == "*") break;
        
        for(int i=0; i<26; i++) {
            chk[i] = 0;
        }

        for(int i=0; i<s.size(); i++) {
            if(s[i] == ' ') continue;
            chk[s[i] - 'a'] = 1;
        }

        bool flag = true;
        for(int i=0; i<26; i++) {
            if(!chk[i]) {
                flag = false;
                break;
            }
        }

        if(flag) cout << "Y" << "\n";
        else cout << "N" << "\n";

    }

}