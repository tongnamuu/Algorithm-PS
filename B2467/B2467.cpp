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
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        if (x >= 0) pos.emplace_back(x);
        else if (x < 0) neg.emplace_back(-x);
    }
    if (pos.empty()) {
        cout << -neg[neg.size() - 2] << ' ' << -neg[neg.size() - 1];
        return 0;
    }
    if (neg.empty()) {
        cout << pos[0] << ' ' << pos[1];
        return 0;
    }
    int ans1 = -neg[0], ans2 = pos[0];
    int val = abs(ans2 + ans1);
    if (neg.size() >= 2) {
        if (val > neg[neg.size()-1] + neg[neg.size() - 2]) {
            val = neg[neg.size() - 1] + neg[neg.size() - 2];
            ans1 = -neg[neg.size() - 1], ans2 = -neg[neg.size() - 2];
        }
    }
    if (pos.size() >= 2) {
        if (val > pos[0] + pos[1]) {
            val = pos[0] + pos[1];
            ans1 = pos[0], ans2 = pos[1];
        }
    }
    for (int i = 0; i < neg.size(); ++i) {
        int idx1 = lower_bound(pos.begin(), pos.end(), neg[i]) - pos.begin();
        if(idx1 < pos.size()) {
            if (neg[i] == pos[idx1]) {
                cout << -neg[i] << ' ' << pos[idx1];
                return 0;
            }
            if (abs(pos[idx1] - neg[i]) < val) {
                val = abs(pos[idx1] - neg[i]);
                ans1 = -neg[i], ans2 = pos[idx1];
            }
        }
        if (idx1 > 0) {
            int idx2 = idx1 - 1;
            if (neg[i] == pos[idx2]) {
                cout << -neg[i] << ' ' << pos[idx2];
                return 0;
            }
            if (abs(pos[idx2] - neg[i]) < val) {
                val = abs(pos[idx2] - neg[i]);
                ans1 = -neg[i], ans2 = pos[idx2];
            }
        }
    }
    cout << ans1 << ' ' << ans2;
}