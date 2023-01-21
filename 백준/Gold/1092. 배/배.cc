#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define INF 1e9

const int mxN = 55, mxM = 1e4+20;
int n, m;
vector<int> crane, box;

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    cin >> n;
    int mxC = 0, mxB = 0;
    for(int i=0; i<n; i++) {
        int x; cin >> x;
        crane.push_back(x);
        mxC = max(mxC, x);
    }
    cin >> m;
    for(int i=0; i<m; i++) {
        int x; cin >> x;
        box.push_back(x);
        mxB = max(mxB, x);
    }

    if(mxC < mxB) {
        cout << -1;
    }
    else {
        sort(crane.begin(), crane.end(), cmp);
        sort(box.begin(), box.end(), cmp);

        int ans = 0;
        while(box.size() != 0) {
            for(int i=0; i<crane.size(); i++) {
                for(int j=0; j<box.size(); j++) {
                    if(crane[i] >= box[j]) {
                        box.erase(box.begin() + j);
                        break;
                    }
                }
            }
            ans++;
        }

        cout << ans;
    }
} 
