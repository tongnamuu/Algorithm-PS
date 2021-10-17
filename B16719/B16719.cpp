#include <iostream>
#include <string>
using namespace std;
int check[101];
void solve(string& s, int l, int r) {
    if (l > r) return;
    int idx = -1;
    for (int i = l; i <= r; ++i) {
        if (!check[i] && (idx==-1 || s[i] < s[idx])) {
            idx = i;
        }
    }
    if (idx == -1) return;
    check[idx] = 1;
    for (int i = 0; i < s.size(); ++i) {
        if (check[i]) cout << s[i];
    }
    cout << '\n';
    solve(s, idx + 1, r);
    solve(s, l, idx - 1);
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    string s; cin >> s;
    solve(s, 0, s.size() - 1);
}
