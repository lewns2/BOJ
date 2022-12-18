#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define INF 1e9



int main() {
    int n; cin >> n;
    string s; cin >> s;

    int idx = 0;
    int ansB = 0, ansS = 0;

    while(idx < s.size()) {
        if(s[idx] == 's' && s.substr(idx, 8) == "security") {
            ansS++;
            idx += 7;
        }
        else if(s[idx] == 'b' && s.substr(idx, 7) == "bigdata") {
            ansB++;
            idx += 6;
        }
        idx++;
    }

    if(ansB < ansS) cout << "security!";
    else if(ansS < ansB) cout << "bigdata?";
    else if(ansS == ansB) cout << "bigdata? security!";
} 