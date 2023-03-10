#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1e9

vector<string> ar;
vector<int> ans;

bool cmp(string a, string b) {
    if(a.size() == b.size()) {
        return a < b;
    }

    return a.size() < b.size();
}

string eraseZero(string x) {
    
    int pos = 0;
    while(x[pos] == '0') {
        pos++;
    }

    if(pos > x.size()-1) {
        pos--;
    }

    return x.substr(pos);
}

int solve(string s, int idx) {
    string tmp = "";
    int pos = idx;
    bool flag = false;

    for(int i=idx; i<s.size(); i++) {
        if(s[i] - '0' >= 0 && s[i] - '0' <= 9) {
            tmp += s[i];
        }
        else {
            pos = i;
            flag = true;
            break;
        }
    }

    if(!flag) pos = s.size()-1;

    if(tmp[0] == '0') {
        tmp = eraseZero(tmp);
    }
    
    ar.push_back(tmp);

    return pos;
}


int main () {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    for(int i=0; i<n; i++) {
        string s; cin >> s;
        int pos = 0;
        while(pos < s.size()) {
            if(s[pos] - '0' >= 0 && s[pos] - '0' <= 9) {
                int nxt = solve(s, pos);
                pos = nxt;
            }
            pos++;
        }
    }

    sort(ar.begin(), ar.end(), cmp);

    for(auto x : ar) {
        cout << x << "\n";
    }
}