#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9

vector<pair<int, pair<int, int>>> ar;
vector<pair<int, pair<int, int>>> res;

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    ar.resize(11);
    for(int i=1; i<=9; i++) {
        string a, b, c; cin >> a >> b >> c;
        int A = 0, B = 0, C = 0;
        if(a == "CIRCLE") A = 0;
        else if(a == "SQUARE") A = 1;
        else if(a == "TRIANGLE") A = 2;
        if(b == "YELLOW") B = 0;
        else if(b == "RED") B = 1;
        else if(b == "BLUE") B = 2;
        if(c == "GRAY") C = 0;
        else if(c == "BLACK") C = 1;
        else if(c == "WHITE") C = 2;
        ar[i] = {A, {B, C}};
    }

    for(int i=1; i<=7; i++) {
        for(int j=i+1; j<=8; j++) {
            for(int k=j+1; k<=9; k++) {
                int s1 = ar[i].first, s2 = ar[j].first, s3 = ar[k].first;
                int c1 = ar[i].second.first, c2 = ar[j].second.first, c3 = ar[k].second.first;
                int b1 = ar[i].second.second, b2 = ar[j].second.second, b3 = ar[k].second.second;
                if(s1 == s2 && s2 == s3) {
                    if(c1 == c2 && c2 == c3) {
                        if(b1 == b2 && b2 == b3) {
                            res.push_back({i, {j, k}});
                        }
                        if(b1 != b2 && b2 != b3 && b1 != b3) {
                            res.push_back({i, {j, k}});
                        }
                    }
                    else if(c1 != c2 && c2 != c3 && c1 != c3) {
                        if(b1 == b2 && b2 == b3) {
                            res.push_back({i, {j, k}});
                        }
                        if(b1 != b2 && b2 != b3 && b1 != b3) {
                            res.push_back({i, {j, k}});
                        }
                    }
                }
                else if(s1 != s2 && s2 != s3 && s1 != s3) {
                    if(c1 == c2 && c2 == c3) {
                        if(b1 == b2 && b2 == b3) {
                            res.push_back({i, {j, k}});
                        }
                        if(b1 != b2 && b2 != b3 && b1 != b3) {
                            res.push_back({i, {j, k}});
                        }
                    }
                    else if(c1 != c2 && c2 != c3 && c1 != c3) {
                        if(b1 == b2 && b2 == b3) {
                            res.push_back({i, {j, k}});
                        }
                        if(b1 != b2 && b2 != b3 && b1 != b3) {
                            res.push_back({i, {j, k}});
                        }
                    }
                }
            }
        }
    }

    int sz = res.size();
    vector<bool> vis(sz);
    // for(auto x : res) {
    //     cout << x.first <<  " " << x.second.first << " " << x.second.second << "\n";
    // }
    int ans = 0;
    bool flag = false;
    int q; cin >> q;
    while(q--) {
        char x; cin >> x;
        if(x == 'H') {
            int x, y, z; cin >> x >> y >> z;
            if(x > y) swap(x, y);
            if(y > z) swap(y, z);
            if(x > y) swap(x, y);

            bool ok = false;
            for(int i=0; i<res.size(); i++) {
                if(x == res[i].first && y == res[i].second.first && z == res[i].second.second) {
                    if(!vis[i]) {
                        ok = true;
                        ans++;
                        vis[i] = 1;
                    }
                    else {
                        ok = true;
                        ans--;
                    }
                    break;
                }
            }
            if(!ok) ans--;

        }
        else if(x == 'G') {
            bool ok = true;
            for(int i=0; i<res.size(); i++) {
                if(!vis[i]) {
                    ok = false;
                    break;
                }
            }
            if(!ok) ans--;
            else if(ok && flag) ans--;
            else if(ok && !flag) {
                ans += 3;
                flag = true;
            }
        }
    }
    cout << ans;
    
}
/*
모양, 색, 배경
circle = 0, square = 1, triangle = 2;
yellow = 0, red = 1, blue = 2;
gray = 0, black = 1, white = 2;


*/
