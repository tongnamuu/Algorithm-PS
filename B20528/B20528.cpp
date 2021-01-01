#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n; cin >> n;
    string s; cin >> s;
    char x = s[0];
    for (int i = 1; i < n; ++i) {
        cin >> s;
        if (s[0] != x) {
            cout << 0;
            return 0;
        }
    }
    cout << 1;
}
