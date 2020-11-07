#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    string s, p;
    getline(cin, s);
    getline(cin, p);
    int n = s.length();
    int m = p.length();
    int i = 0;
    int ans = 0;
    while (i + m <= n){
        bool find = true;
        int j = i;
        for (; j < i + m; ++j) {
            if (p[j - i] != s[j]) {
                find = false; break;
            }
        }
        if (find) {
            i = j;
            ++ans;
        }
        else i += 1;
    }
    cout << ans;
}