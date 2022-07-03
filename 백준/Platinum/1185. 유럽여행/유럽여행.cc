#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define INFL 1e18
#define INF 1e9

const int mxN = 1e4+10;
int n, p, c[mxN];
vector<pair<int, pair<int, int>>> arr;
int par[mxN];

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
    cin >> n >> p; 
    int mi = 1010;
    for(int i=1; i<=n; i++) {
        cin >> c[i];
        mi = min(mi, c[i]);
        par[i] = i;
    }
    for(int i=0; i<p; i++) {
        int fr, to, val; cin >> fr >> to >> val;
        int v =  c[fr] + c[to] + (2 * val);
        arr.push_back({v, {fr, to}});
        arr.push_back({v, {to, fr}});
    }
    sort(arr.begin(), arr.end());

    int ans = 0;
    for(int i=0; i<arr.size(); i++) {
        int cost = arr[i].first;
        int x = arr[i].second.first;
        int y = arr[i].second.second;
        if(merge(x, y)) {
            ans += cost;
        }
    }
    cout << ans + mi;

}
