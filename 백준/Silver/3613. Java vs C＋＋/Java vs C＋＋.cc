#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define INFL 2e18
#define INF 1e9

// boj 3613
// long_and_mnemonic_identifier longAndMnemonicIdentifier
// longAndMnemonicIdentifier long_and_mnemonic_identifier 
int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string s; cin >> s;
    
    bool isC = false;
    bool isJava = false;

    if(s[0] - 'a' < 0 || s[s.size()-1] == '_') {
        isC = 1;
        isJava = 1; 
    }

    for(int i=0; i<s.size(); i++) {
        if(s[i] == '_') {
            isC = true;
        }
        if(isC) break;
    }

    for(int i=0; i<s.size(); i++) {
        if(s[i] - 'a' < 0 && s[i] != '_') {
            isJava = true;
        }
        if(isJava) break;
    }

    string ans = "";
    if(isC && isJava) {
        ans = "Error!";
    } else {
        if(isJava) {
            for(int i=0; i<s.size(); i++) {
                if(s[i] -'a' < 0) { // 대문자
                    ans += '_';
                    ans +=  char(s[i]+32); // 소문자 변환
                } else {
                    ans += s[i];
                }
            }
        } 
        else {
            for(int i=0; i<s.size(); i++) {

                if(s[i] == '_' && s[i+1] == '_') {
                    ans = "Error!";
                    break;
                }
                
                if(s[i] == '_' && i != s.size() -1 ) {
                    ans += char(s[i+1] - 32);
                    i++;
                } else {
                    ans += s[i];
                }

                if(ans == "Error!") break;
            }    
        }
    } 
    cout << ans;
}