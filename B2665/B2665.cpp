#include <iostream>
#include <queue>
using namespace std;
#define INF 1000000000
struct Edge {
    int x, y, c;
    bool operator<(const Edge& a) const {
        return a.c < this->c;
    }
};
char a[51][51];
int d[51][51];
const int dx[] = { 0,0,-1,1 };
const int dy[] = { -1,1,0,0 };
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        for (int j = 0; j < n; ++j) {
            d[i][j] = INF;
        }
    }
    priority_queue<Edge>q;
    d[0][0] = 0;
    q.push({ 0,0,0 });
    while (!q.empty()) {
        Edge e = q.top();
        q.pop();
        if (d[e.x][e.y] < e.c) continue;
        for (int dir = 0; dir < 4; ++dir) {
            int nx = e.x + dx[dir];
            int ny = e.y + dy[dir];
            if (nx >= 0 && nx < n&&ny >= 0 && ny < n) {
                int nc = e.c + (a[nx][ny] == '0');
                if (d[nx][ny] > nc) {
                    d[nx][ny] = nc;
                    q.push({ nx,ny,nc });
                }
            }
        }
    }
    cout << d[n - 1][n - 1];
}
