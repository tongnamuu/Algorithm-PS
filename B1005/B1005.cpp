#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct NodeTimeInfo {
    int now, time;
    bool operator<(const NodeTimeInfo& a) const {
        return time > a.time;
    }
};
#define N 1001
int indegree[N];
int a[N];
vector<int>adj[N];
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int n, k; cin >> n >> k;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            adj[i].clear();
            indegree[i] = 0;
        }
        for (int i = 0, u, v; i < k; ++i) {
            cin >> u >> v;
            indegree[v] += 1;
            adj[u].push_back(v);
        }
        int w; cin >> w;
        priority_queue<NodeTimeInfo>q;
        for (int i = 1; i <= n; ++i) {
            if (!indegree[i]) q.push({ i,a[i] });
        }
        while (!q.empty()) {
            int now = q.top().now;
            int time = q.top().time;
            if (now == w) {
                cout << time << '\n';
                break;
            }
            q.pop();
            for (int next : adj[now]) {
                indegree[next]--;
                if (indegree[next] == 0) {
                    q.push({ next, a[next] + time });
                }
            }
        }
    }
}
