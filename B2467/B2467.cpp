#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n; cin >> n;
    if (n == 2) {
        int a, b; cin >> a >> b;
        cout << a << ' ' << b;
        return 0;
    }
    vector<int>neg;
    vector<int>pos;
    int zero = 0;
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        if (x == 0) zero += 1;
        if (x >= 0) pos.emplace_back(x);
        else if (x < 0) neg.emplace_back(-x);
    }
    if (zero >= 2) {
        cout << 0 << ' ' << 0;
        return 0;
    }
    if (neg.empty()) {
        cout << pos[0] << ' ' << pos[1] << '\n';
        return 0;
    }
    sort(neg.begin(), neg.end());
    if (pos.empty()) {
        cout << -neg[1] << ' ' << -neg[0];
        return 0;
    }
    int val = 2000000001;
    int ans1 = 1000000000;
    int ans2 = 1000000000;
    if (pos.size() >= 2) {
        if (pos[0] + pos[1] <= val) {
            ans1 = pos[0];
            ans2 = pos[1];
            val = pos[0] + pos[1];
        }
    }
    if (neg.size() >= 2) {
        if (neg[0] + neg[1] <= val) {
            ans1 = -neg[1];
            ans2 = -neg[0];
            val = neg[0] + neg[1];
        }
    }
    for (int v : neg) {
        int idx = lower_bound(pos.begin(), pos.end(), v) - pos.begin();
        if (idx) {
            if (abs(pos[idx - 1] - v) <= val) {
                ans2 = pos[idx - 1];
                ans1 = -v;
                val = abs(pos[idx - 1] - v);
            }
        }
        if (idx<pos.size() && abs(pos[idx] - v) <= val) {
            ans2 = pos[idx];
            ans1 = -v;
            val = abs(pos[idx] - v);
        }
    }
    cout << ans1 << ' ' << ans2;
}
