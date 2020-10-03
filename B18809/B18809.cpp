#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
#define G 3
#define R 4
const int dx[] = { 0,0,-1,1 };
const int dy[] = { -1,1,0,0 };
int map[51][51];
int a[51][51];
int gd[51][51];
int rd[51][51];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n, m, g, r; cin >> n >> m >> g >> r;
    vector<pair<int, int>>pos;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            map[i][j] = a[i][j];
            if (a[i][j] == 2) {
                pos.push_back({ i,j });
            }
        }
    }
    vector<int>temp;
    int k = pos.size();
    for (int i = 0; i < k - g - r; ++i) {
        temp.push_back(2);
    }
    for (int i = 0; i < g; ++i) {
        temp.push_back(G);
    }
    for (int i = 0; i < r; ++i) {
        temp.push_back(R);
    }
    int ans = 0;
    queue<pair<int, int>>rq;
    queue<pair<int, int>>gq;
    do {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                a[i][j] = map[i][j];
                gd[i][j] = -1;
                rd[i][j] = -1;
            }
        }
        for (int i = 0; i < k; ++i) {
            a[pos[i].first][pos[i].second] = temp[i];
            if (temp[i] == G) {
                gq.push({ pos[i].first, pos[i].second });
                gd[pos[i].first][pos[i].second] = 0;
            }
            else if (temp[i] == R) {
                rq.push({ pos[i].first, pos[i].second });
                rd[pos[i].first][pos[i].second] = 0;
            }
        }
        int temp = 0;
        while (!rq.empty() || !gq.empty()) {
            int c = rq.size();
            while (c--) {
                int x = rq.front().first;
                int y = rq.front().second;
                rq.pop();
                if (a[x][y] == 5) continue;
                for (int dir = 0; dir < 4; ++dir) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    if (nx >= 0 && nx < n&&ny >= 0 && ny < m && a[nx][ny] && rd[nx][ny] == -1) {
                        if (a[nx][ny] <= 2) {
                            a[nx][ny] = R;
                            rq.push({ nx,ny });
                            rd[nx][ny] = rd[x][y] + 1;
                        }
                    }
                }
            }
            c = gq.size();
            while (c--) {
                int x = gq.front().first;
                int y = gq.front().second;
                gq.pop();
                if (a[x][y] == 5) continue;
                for (int dir = 0; dir < 4; ++dir) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    if (nx >= 0 && nx < n&&ny >= 0 && ny < m && a[nx][ny] && gd[nx][ny] == -1) {
                        if (a[nx][ny] <= 2) {
                            a[nx][ny] = G;
                            gq.push({ nx,ny });
                            gd[nx][ny] = gd[x][y] + 1;
                        }
                        else if (a[nx][ny] == R) {
                            if (rd[nx][ny] == gd[x][y] + 1) {
                                a[nx][ny] = 5;
                                ++temp;
                            }
                        }
                    }
                }
            }
        }
        ans = max(ans, temp);
    } while (next_permutation(temp.begin(), temp.end()));
    cout << ans;
}