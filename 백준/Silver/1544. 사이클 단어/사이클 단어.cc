#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define INF 1e9

const int mxN = 55;
int n;
int par[mxN];
vector<string> words;
vector<string> ar[mxN];

void sol(string s, int idx) {

    for(int i=0; i<s.size(); i++) {
        string pre = s.substr(0, i+1);
        string suf = "";
        for(int j=i+1; j<s.size(); j++) {
            suf += s[j];
        }
        string res = suf + pre;
        ar[idx].push_back(res);
    }
}

int find(int x) {
    if(par[x] == x) return x;
    return par[x] = find(par[x]);
}

bool merge(int a, int b) {
    a = find(a), b = find(b);
    if(a == b) return false;
    if(a > b) swap(a, b);
    par[a] = b;

    return true;
}


int main() {
    cin >> n;

    for(int i=0; i<n; i++) {
        par[i] = i;
    }

    for(int i=0; i<n; i++) {
        string s; cin >> s;
        words.push_back(s);
        sol(s, i);
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<ar[i].size(); j++) {
            for(int k=0; k<n; k++) {
                if(ar[i][j] == words[k]) {
                    merge(i, k);
                }
            }
        }
    }
    set<int> st;
    for(int i=0; i<n; i++) {
        st.insert(par[i]);
    }
    cout << st.size();
} 
