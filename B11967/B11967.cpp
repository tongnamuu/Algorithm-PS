#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int d[101][101];
bool bright[101][101];
bool InQ[101][101];
vector<int>adj[11001];
const int dx[] = { -1,1,0,0 };
const int dy[] = { 0,0,-1,1 };
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0, x1, y1, x2, y2; i < m; ++i) {
        cin >> x1 >> y1 >> x2 >> y2;
        adj[x1 * 101 + y1].push_back(x2 * 101 + y2);
    }
    queue<pair<int, int>>q;
    d[1][1] = 1;
    q.push({ 1,1 });
    int ans = 0;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        ++ans;
        for (int next : adj[x * 101 + y]) {
            int t1 = next / 101;
            int t2 = next % 101;
            bright[t1][t2] = true;
            if (InQ[t1][t2] && !d[t1][t2]) {
                d[t1][t2] = 1;
                q.push({ t1,t2 });
            }
        }
        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx > 0 && nx <= n && ny > 0 && ny <= n) {
                InQ[nx][ny] = true;
                if (bright[nx][ny] && !d[nx][ny]) {
                    d[nx][ny] = 1;
                    q.push({ nx,ny });
                }
            }
        }
    }
    cout << min(ans,n*n);
}