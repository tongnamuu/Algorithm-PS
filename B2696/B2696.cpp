#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;
void solve() {
    int n; cin >> n;
    priority_queue<int, vector<int>, greater<int>>right;
    priority_queue<int>left;
    if (n == 1) {
        cin >> n; cout << 1 << '\n' << n << '\n';
        return;
    }
    int x, y; cin >> x >> y;
    if (x > y) right.push(x), left.push(y);
    else left.push(x), right.push(y);
    vector<int>ans;
    ans.push_back(x);
    for (int i = 3, x; i <= n; ++i) {
        cin >> x;
        if (i & 1) {
            if (right.top() >= x) {
                if (left.top() >= x) {
                    right.push(left.top());
                    left.pop();
                    left.push(x);
                }
                else {
                    right.push(x);
                }
            }
            else {
                right.push(x);
            }
            ans.push_back(right.top());
        }
        else {
            if (x > right.top()) {
                left.push(right.top());
                right.pop();
                right.push(x);
            }
            else {
                left.push(x);
            }
        }
    }
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i];
        if ((i + 1) % 10 == 0) cout << '\n';
        else cout << ' ';
    }
    cout << '\n';
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}
