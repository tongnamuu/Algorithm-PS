#include <iostream>
#include <set>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        multiset<int>s;
        for (int i = 0; i < n; ++i) {
            char cmd; int num; cin >> cmd >> num;
            if (cmd == 'I') {
                s.insert(num);
            }
            else if (cmd == 'D') {
                if (s.empty()) continue;
                if (num == 1) {
                    s.erase(--s.end());
                }
                else if (num == -1) {
                    s.erase(s.begin());
                }
            }
        }
        if (s.empty()) cout << "EMPTY\n";
        else {
            cout << *--s.end() << ' ' << *s.begin() << '\n';
        }
    }
}
