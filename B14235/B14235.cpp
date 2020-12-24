#include <iostream>
#include <queue>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n; cin >> n;
    priority_queue<int>q;
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        if (!x) {
            if (q.empty())cout << -1 << '\n';
            else {
                cout << q.top() << '\n';
                q.pop();
            }
        }
        for (int j = 0, num; j < x; ++j) {
            cin >> num;
            q.push(num);
        }
    }
}
