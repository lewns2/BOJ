#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define INF 1e9

const int mxN = 2e5+10;
int n;
int num[mxN], vis[mxN];
vector<pair<int, int>> A, B, C, D;
vector<int> ans;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if(a.first == b.first) {
        return a.second < b.second;
    }
    
    return a.first > b.first;
}

void sol(vector<pair<int, int>> ar) {

    bool ok = false;
    for(auto x : ar) {
        if(!vis[x.second]) {
            vis[x.second] = 1;
            ans.push_back(x.second);
            ok = true;
        }
        if(ok) break;
    }
}

int main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> num[i];
        int a, b, c, d; cin >> a >> b >> c >> d;
        A.push_back({a, num[i]});
        B.push_back({b, num[i]});
        C.push_back({c, num[i]});
        D.push_back({d, num[i]});
    }
    
    sort(A.begin(), A.end(), cmp);
    sort(B.begin(), B.end(), cmp);
    sort(C.begin(), C.end(), cmp);
    sort(D.begin(), D.end(), cmp);

    ans.push_back(A[0].second);
    vis[A[0].second] = 1;

    sol(B);
    sol(C);
    sol(D);

    for(auto x : ans) {
        cout << x << " ";
    }
    
} 
