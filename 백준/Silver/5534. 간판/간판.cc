#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1e9

const int mxN = 25;
int n;
string s;

bool solve(string ref, int space) {

    bool flag = false;
    
    for(int i=0; i<ref.size(); i++) {
        string tmp = "";
        for(int j=i; j<ref.size(); j+=space) {
            tmp += ref[j];
            if(tmp.size() == s.size()) {
                if(tmp == s) {
                    flag = true;
                }
                break;
            }
        }
        if(flag) break;
    }

    return flag;
}

int main () {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    cin >> s;
    int ans = 0;
    for(int i=0; i<n; i++) {
        string x; cin >> x;
        int sz = x.size();

        // 간격 크기
        bool isOk = false;
        for(int j=0; j<sz; j++) {
            // solve(x,j+1);
            if(solve(x,j+1)) {
                isOk = true;
            }
            if(isOk) break;
        }
        ans += isOk;
    }

    cout << ans;
}

/*

*/