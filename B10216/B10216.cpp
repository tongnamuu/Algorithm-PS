#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define N 3001
int x[N];
int y[N];
int r[N];
vector<int>adj[N];
int visit[N];
bool near(int i, int j) {
    int dist = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) *(y[i] - y[j]);
    int c = r[i] + r[j];
    return dist <= c * c;
}
void dfs(int now) {
    visit[now] = 1;
    for (int next : adj[now]) {
        if(!visit[next]) dfs(next);
    }
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> x[i] >> y[i] >> r[i];
            visit[i] = 0;
            adj[i].clear();
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (near(i, j)) adj[i].push_back(j), adj[j].push_back(i);
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (!visit[i]) {
                ++ans;
                dfs(i);
            }
        }
        cout << ans << '\n';
    }
}
