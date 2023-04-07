#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1e9


int main () {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    int sz = 0;
    
    vector<string> ar;

    for(int i=0; i<n; i++) {
        string s; cin >> s;
        ar.push_back(s);
        sz = s.size();
    }

    vector<char> ans(sz+10);

    for(int i=0; i<sz; i++) {
        char ref = ar[0][i];
        bool flag = true;
        for(int j=1; j<ar.size(); j++) {
            if(ref != ar[j][i]) {
                ans[i] = '?';
                flag = false;
                break;
            }
        }
        if(flag) ans[i] = ref;
    }

    for(int i=0; i<sz; i++) {
        cout << ans[i];
    }
}