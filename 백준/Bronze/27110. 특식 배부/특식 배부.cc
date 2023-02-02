#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1e9


const int mxN = 1e3+10;
int n, a, b, c;


int main () {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    cin >> a >> b >> c;
    cout << min(n, a) + min(n, b) + min(c, n);
    
}