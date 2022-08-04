#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9



int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int a, b; cin >> a >> b;
    int c; cin >> c;
    b += c;
    int x = b/60;
    int y = b%60;

    int h = a + x;
    int m = y;
    if(h >= 24) h -= 24;

    cout << h << " " << m;
    
} 