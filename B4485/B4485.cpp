#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define INF 400000
int a[126][126];
int d[126][126];
const int dx[] = { -1,1,0,0 };
const int dy[] = { 0,0,-1,1 };
struct Edge {
    int x, y, c;
    bool operator<(const Edge& u) const {
        return c > u.c;
    }
};
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n;
    for(int tc=1;;++tc){
        cin >> n;
        if (n == 0) break;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> a[i][j];
                d[i][j] = INF;
            }
        }
        priority_queue<Edge>q;
        q.push({ 0,0, 0 });
        d[0][0] = 0;
        while (!q.empty()) {
            auto now = q.top();
            q.pop();
            if (d[now.x][now.y] < now.c) continue;
            for (int dir = 0; dir < 4; ++dir) {
                int nx = now.x + dx[dir];
                int ny = now.y + dy[dir];
                if (nx >= 0 && nx < n&&ny >= 0 && ny < n) {
                    int c = a[now.x][now.y] + d[now.x][now.y];
                    if (d[nx][ny] > c) {
                        q.push({ nx,ny,c });
                        d[nx][ny] = c;
                    }
                }
            }
        }
        cout << "Problem " << tc << ": " << d[n - 1][n - 1] + a[n - 1][n - 1] << '\n';
    }
}