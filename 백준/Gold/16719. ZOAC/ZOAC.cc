#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1e9

string s;
string order;
int vis[110];
char res[110];
string ans = "";

void solve() {

    vector<pair<string, int>> tmpArr;

    // s에서 후보 문자 찾기
    map<int, char> mp;
    for(int i=0; i<s.size(); i++) {
        if(!vis[i]) {
            mp[i] = s[i];

            res[i] = s[i];
            string tmp = "";
            for(int j=0; j<s.size(); j++) {
                if(res[j] == -1) continue;
                tmp += res[j];
            }

            res[i] = -1;

            // 후보 정답 문자열 : tmp
            tmpArr.push_back({tmp, i});
        }
    }

    sort(tmpArr.begin(), tmpArr.end());
    ans = tmpArr[0].first;
    int idx = tmpArr[0].second;
    vis[idx] = 1;
    res[idx] = mp[idx];

    cout << ans << "\n";


}


int main () {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> s;

    order = s;
    sort(order.begin(), order.end());
    int idx = 0;
    int prev = -1;

    memset(res, -1, sizeof(res));
    
    for(int i=0; i<(int)s.size(); i++) {
        solve();
    }

}