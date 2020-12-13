#include <iostream>
#include <vector>
using namespace std;
vector<int>adj[51];
int removed;
void dfs(int now, int p, int& ans) {
    int cnt = 0;
    for (int next : adj[now]) {
        if (next == p || next == removed) continue;
        dfs(next, now, ans);
        ++cnt;
    }
    if (!cnt) ++ans;
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n; cin >> n;
    int root = 0;
    for (int i = 0, num; i < n; ++i) {
        cin >> num;
        if (num == -1) {
            root = i;
            continue;
        }
        adj[num].push_back(i);
        adj[i].push_back(num);
    }
    cin >> removed;
    if (removed == root) {
        cout << 0;
    }
    else {
        int ans = 0;
        dfs(root, -1, ans);
        cout << ans;
    }
}