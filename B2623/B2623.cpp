#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define N 1001
vector<int>adj[N];
int indegree[N];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int cnt, prev; cin >> cnt >> prev;
        for (int j = 1, x; j < cnt; ++j) {
            cin >> x;
            adj[prev].push_back(x);
            prev = x;
            indegree[x] += 1;
        }
    }
    queue<int>q;
    for (int i = 1; i <= n; ++i) {
        if (!indegree[i]) q.push(i);
    }
    vector<int>ans;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        ans.push_back(now);
        for (int next : adj[now]) {
            indegree[next]--;
            if (indegree[next] == 0) {
                q.push(next);
            }
        }
    }
    if (ans.size() != n) cout << 0;
    else {
        for (int x : ans) {
            cout << x << '\n';
        }
    }
}
