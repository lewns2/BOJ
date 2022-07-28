#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9



int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, q; cin >> n >> q;
    set<string> st;
    for(int i=0; i<n; i++) {
        string s; cin >> s;
        st.insert(s);
    }
    while(q--) {
        string x; cin >> x;
        
        string tmp = "";
        for(int i=0; i<x.size(); i++) {
            if(x[i] == ',') continue;
            tmp += x[i];
            if(x[i+1] == ',' || i == x.size()-1)  {
                if(st.find(tmp) != st.end()) {
                    st.erase(tmp);
                }
                tmp = "";
                continue;
            }
        }
        cout << (int)st.size() << "\n";
    }
} 

/*
*/
