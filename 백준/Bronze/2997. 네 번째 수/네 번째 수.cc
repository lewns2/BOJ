#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int ar[4];
    for(int i=0; i<3; i++) {
        cin >> ar[i];
    }
    sort(ar, ar+3);
    int a = ar[1] - ar[0];
    int b = ar[2] - ar[1];
    
    if(a == b) {
        if(ar[0] - a < -100) cout << ar[2] + a;
        else cout << ar[0] - a;
    }
    else if(a == 2 * b) {
        cout << ar[0] + b;
    }
    else if(b == 2 * a) {
        cout << ar[1] + a;
    }
}
