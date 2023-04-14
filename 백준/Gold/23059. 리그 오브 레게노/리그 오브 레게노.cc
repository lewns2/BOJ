#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1e9

const int mxN = 2e5*2+10;
int n;
unordered_map<string, int> mp;
unordered_map<int, string> rmp;
vector<int> ar[mxN];
int degree[mxN];
queue<int> q;
vector<string> ans;

// string 순으로 정렬
void solve(vector<int> res) {
    vector<string> strArr;
    for(int i=0; i<res.size(); i++) {
        strArr.push_back(rmp[res[i]]);
    }
    sort(strArr.begin(), strArr.end());
    for(int i=0; i<strArr.size(); i++) {
        q.push(mp[strArr[i]]);
    }
}

int main () {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    int idx = 1;
    for(int i=0; i<n; i++) {
        string a, b; cin >> a >> b;
        if(!mp[a]) {
            mp[a] = idx;
            rmp[idx] = a;
            idx++;
            
        }
        if(!mp[b]) {
            mp[b] = idx;
            rmp[idx] = b;
            idx++;
        }
        int A = mp[a], B = mp[b];
        
        ar[A].push_back(B);
        degree[B]++;
    }

    vector<int> tmp;
    for(int i=1; i<idx; i++) {
        if(degree[i] == 0) {
            tmp.push_back(i);
            // q.push(i);
        }
    }
    solve(tmp);
    int cycle = tmp.size();
    tmp.clear();
    int cnt = 0;

    while(q.size()) {
        int x = q.front();
        q.pop();
        cnt++;

        ans.push_back(rmp[x]);

        for(int i=0; i<ar[x].size(); i++) {
            int nxt = ar[x][i];
            if(--degree[nxt] == 0) {
                tmp.push_back(nxt);
                // q.push(nxt);
            }
        }

        if(cnt == cycle) {
            cnt = 0;
            solve(tmp);
            cycle = tmp.size();
            tmp.clear();
        }    
    }

    if(ans.size() != idx-1) {
        cout << -1;
    } else {
        for(auto x : ans) {
            cout << x << "\n";
        }
    }
}

/*

*/