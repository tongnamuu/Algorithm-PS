#include <iostream>
#include <map>
#include <string>
using namespace std;
string a[100001];
map<string, int> m;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        m[a[i]] = i;
    }
    for (int i = 0; i < q; ++i) {
        string cmd; cin >> cmd;
        if (cmd[0] >= '0' && cmd[0] <= '9') {
            cout << a[stoi(cmd)] << '\n';
        }
        else {
            cout << m[cmd] << '\n';
        }
    }
}
