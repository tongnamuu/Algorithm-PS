#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        map<string, vector<string>> m;
        for (int i = 0; i < n; ++i) {
            string u, v;
            cin >> u >> v;
            m[v].push_back(u);
        }
        long long ans = 1;
        for (auto i = m.begin(); i != m.end(); ++i) {
            ans *= (i->second.size() + 1);
        }
        cout << ans - 1 << '\n';
    }
}
