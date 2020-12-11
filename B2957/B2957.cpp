#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n; cin >> n;
    int val; cin >> val;
    map<int, long long>depth;
    depth[val] = 0;
    long long ans = 0;
    cout << ans << '\n';
    for (int i = 1; i < n; ++i) {
        cin >> val;
        auto it = depth.lower_bound(val);
        long long d1 = 0, d2 = 0;
        if (it != depth.end()) {
            d1 = it->second;
        }
        if (it != depth.begin()) {
            it--;
            d2 = it->second;
        }
        long long c = max(d1, d2) + 1;
        ans += c;
        depth[val] = c;
        cout << ans << '\n';
    }
}