#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, int>>adj[100001];
int dfs(int now, int p, int cur, int& s, int& ans) {
    int res = 0;
    for (auto k : adj[now]) {
        if (k.first == p) continue;
        int d = dfs(k.first, now, cur + k.second, s, ans);
        res = max(res, d);
    }
    if (!res) {
        if (ans < cur) {
            ans = cur;
            s = now;
        }
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n; cin >> n;
    for (int i = 0, u, v, c; i < n; ++i) {
        cin >> u;
        while (1) {
            cin >> v;
            if (v == -1) break;
            cin >> c;
            adj[u].push_back({ v,c });
        }
    }
    int s = 1, ans = 0;
    dfs(s, s, 0, s, ans);
    dfs(s, s, 0, s, ans);
    cout << ans;
}
