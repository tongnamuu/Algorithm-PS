#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define N 101
int d[N][N];
bool bright[N][N];
bool InQ[N][N];
vector<pair<int, int>>adj[N][N];
const int dx[] = { -1,1,0,0 };
const int dy[] = { 0,0,-1,1 };
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0, x1, y1, x2, y2; i < m; ++i) {
        cin >> x1 >> y1 >> x2 >> y2;
        adj[x1][y1].push_back({ x2,y2 });
    }
    queue<pair<int, int>>q;
    d[1][1] = 1;
    q.push({ 1,1 });
    bright[1][1] = true;
    InQ[1][1] = true;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (auto next : adj[x][y]) {
            int t1 = next.first;
            int t2 = next.second;
            bright[t1][t2] = true;
            if (InQ[t1][t2] && !d[t1][t2]) {
                d[t1][t2] = 1;
                q.push({ t1,t2 });
            }
        }
        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= n) {
                InQ[nx][ny] = true;
                if (bright[nx][ny] && !d[nx][ny]) {
                    d[nx][ny] = 1;
                    q.push({ nx,ny });
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            ans += bright[i][j];
        }
    }
    cout << ans << '\n';
}