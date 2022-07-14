#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9

const int mxN = 1e3+10;
int n, m;
int par[mxN];
vector<pair<int, pair<int, int>>> arr;

int find(int x) {
    if(par[x] == x) return x;
    return par[x] = find(par[x]);
}

bool merge(int a, int b) {
    a = find(a);
    b = find(b);
    if(a == b) return false;

    if(a < b) swap(a, b);
    par[a] = b;
    return true;

}

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    
    for(int i=1; i<=n; i++) {
        par[i] = i;
    }

    for(int i=0; i<m; i++) {
        int fr, to, val; cin >> fr >> to >> val;
        arr.push_back({val, {fr, to}});
        arr.push_back({val, {to, fr}});
    }
    
    int ans = 0;
    sort(arr.begin(), arr.end());
    for(int i=0; i<arr.size(); i++) {
        int c = arr[i].first;
        int s = arr[i].second.first;
        int e = arr[i].second.second;

        if(merge(s, e)) {
            ans += c;
        }
    }
    cout << ans;

} 