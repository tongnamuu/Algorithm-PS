#include <iostream>
#include <queue>
using namespace std;
int n;
int w[1001][1001];
int visit[1001];
void dfs(int node) {
    cout << node << ' ';
    visit[node] = 1;
    for (int i = 1; i <= n; i++) {
        if (w[node][i] == 1 && !visit[i]) {
            dfs(i);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    int m, start; cin >> n >> m >> start;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        w[u][v] = 1;
        w[v][u] = 1;
    }
    dfs(start);
    cout << '\n';
    queue<int>q;
    q.push(start);
    visit[start] = 2;
    while (!q.empty()){
        int nx = q.front(); q.pop();
        cout << nx << ' ';
        for (int i = 1; i <= n; i++) {
            if (w[nx][i] == 1 && visit[i] == 1) {
                visit[i] = 2;
                q.push(i);
            }
        }
    }
}