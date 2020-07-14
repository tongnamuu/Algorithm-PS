#include <iostream>
#include <stack>
using namespace std;
stack<int>s[7];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n, p; cin >> n >> p;
    int ans = 0;
    for (int i = 0, u, v; i < n; ++i) {
        cin >> u >> v;
        while (!s[u].empty() && s[u].top() > v) {
            ++ans;
            s[u].pop();
        }
        if (!s[u].empty() && s[u].top() == v) continue;
        s[u].push(v);
        ++ans;
    }
    cout << ans;
}