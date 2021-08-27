#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
char a[103][103];
int d[103][103];
const int dx[4] = { 0,0,-1,1 };
const int dy[4] = { -1,1,0,0 };
vector<pair<int, int>> alp[26];
int enQ[26];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int n, m; cin >> n >> m;
        for (int i = 1; i <= n; ++i) {
            cin >> (a[i] + 1);
        }
        for (int i = 0; i < 26; ++i) alp[i].clear(), enQ[i] = 0;
        cin >> a[0];
        for (int i = 0; a[0][i]; ++i) {
            if (a[0][i] >= 'a' && a[0][i] <= 'z') {
                enQ[a[0][i] - 'a'] = 1;
            }
        }
        n++; m++;
        for (int i = 0; i <= n; ++i) a[i][0] = a[i][m] = '.';
        for (int i = 0; i <= m; ++i) a[0][i] = a[n][i] = '.';
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                d[i][j] = -1;
            }
        }
        queue<pair<int, int>>q;
        q.push({ 0,0 });
        d[0][0] = 0;
        int ans = 0;
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            if (a[x][y] == '$') ++ans;
            q.pop();
            for (int dir = 0; dir < 4; ++dir) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if (nx >= 0 && nx <= n && ny >= 0 && ny <= m && d[nx][ny]==-1) {
                    if (a[nx][ny] == '.'|| a[nx][ny] == '$') {
                        q.push({ nx,ny });
                        d[nx][ny] = 0;                 
                    } 
                    else if (a[nx][ny] >='a' && a[nx][ny]<='z') {
                        q.push({ nx,ny });
                        d[nx][ny] = 1;
                        if (!enQ[a[nx][ny] - 'a']) {
                            enQ[a[nx][ny] - 'a'] = 1;
                            for (auto& k : alp[a[nx][ny] - 'a']) {
                                q.push(k);
                                d[k.first][k.second] = 0;
                            }
                            alp[a[nx][ny] - 'a'].clear();
                        }
                    }
                    else if (a[nx][ny] >= 'A' && a[nx][ny] <= 'Z') {
                        if (enQ[a[nx][ny] - 'A']) {
                            q.push({ nx,ny });
                            d[nx][ny] = 0;
                        }
                        else {
                            alp[a[nx][ny] - 'A'].push_back({ nx,ny });
                        }
                    }
                }
            }
        }
        cout << ans << '\n';
    }
}
