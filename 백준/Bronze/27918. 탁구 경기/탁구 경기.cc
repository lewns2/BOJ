#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1e9


int main () {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;

    bool freeze = false;
    int A = 0, B = 0;
    for(int i=0; i<n; i++) {
        char x; cin >> x;
        if(!freeze) {
            if(x == 'D') A++;
            else B++;
        }

        if(abs(A - B) >= 2) freeze = true;
        
    }    
    cout << A << ":" << B;
}

/*

*/