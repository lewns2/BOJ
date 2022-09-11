#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9

const int mxN = 4, dx[4]={1, -1, 0, 0}, dy[4]={0, 0, 1, -1};
vector<vector<char>> ar;
vector<pair<int, int>> space;
int ans;

vector<vector<char>> paint(vector<vector<char>> board, int x, int y) {
    
    if(board[x][y] == '*') board[x][y] = '.';
    else if(board[x][y] == '.') board[x][y] = '*';

    for(int k=0; k<4; k++) {
        int nx = x+dx[k];
        int ny = y+dy[k];
        if(nx < 0 || nx >= 3 || ny < 0 || ny >=3) continue;
        if(board[nx][ny] == '*') board[nx][ny] = '.';
        else if(board[nx][ny] == '.') board[nx][ny] = '*';
    }

    return board;
}

void solve(vector<vector<char>> board, int k, int idx) {

    if(idx > 9) {
        return;
    }
    
    bool ok = true;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(board[i][j] != ar[i][j]) {
                ok = false;
                break;
            }
        }
        if(!ok) break;
    }

    if(ok) {
        ans = min(ans, k);
    }
    
    int x = space[idx].first;
    int y = space[idx].second;

    solve(paint(board, x, y), k+1, idx+1);
    solve(board, k, idx+1);
    
}

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while(t--) {
        ar.resize(3, vector<char>(3));
        space.clear();
        ans = 1e9;
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                ar[i].clear();
            }
        }

        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                cin >> ar[i][j];
                space.push_back({i, j});
            }
        }
        vector<vector<char>> init;
        init.resize(3, vector<char>(3));
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                init[i][j] = '.';
            }
        }
        solve(init, 0, 0);
        cout << ans << "\n";
    }
} 