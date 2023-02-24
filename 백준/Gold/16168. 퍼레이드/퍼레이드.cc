#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1e9


const int mxN = 3030;
int v, e;
vector<int> ar[mxN];
int degree[mxN], par[mxN];

int find(int x) {
    if(par[x] == x) return x;
    return par[x] = find(par[x]);
}

bool merge(int a, int b) {
    a = find(a);
    b = find(b);
    if(a == b) return false;

    if(a > b) swap(a, b);
    par[a] = b;

    return true;
}

int main () {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> v >> e;

    for(int i=1; i<=v; i++) {
        par[i] = i;
    }

    for(int i=0; i<e; i++) {
        int fr, to; cin >> fr >> to;
        ar[fr].push_back(to);
        ar[to].push_back(fr);
        degree[fr]++; degree[to]++;
        merge(fr, to);
    }

    int odd_degree = 0;
    
    for(int i=1; i<=v; i++) {
        if(degree[i] % 2 == 1) odd_degree++;
    }

    bool isOk = true;
    int same = find(1);
    for(int i=2; i<=v; i++) {
        if(find(i) != same) {
            isOk = false;
            break;
        }
    }

    if(isOk && (odd_degree == 0 || odd_degree == 2)) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
}