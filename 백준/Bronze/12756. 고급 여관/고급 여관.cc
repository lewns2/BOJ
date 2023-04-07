#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1e9



int main () {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int aa, ah; cin >> aa >> ah;
    int ba, bh; cin >> ba >> bh;

    int A = ah / ba;
    if(ah % ba != 0) {
        A++;
    }
    int B = bh / aa;
    if(bh % aa != 0) {
        B++;
    }

    if(A == B) cout << "DRAW";
    else if(A > B) cout << "PLAYER A";
    else cout << "PLAYER B";

}