#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    string str;
    for(int tc=1;;++tc) {
        cin >> str;
        if (str[0] == '-') break;
        stack<char>s;
        int ans = 0;
        for (char ch : str) {
            if (ch == '}') {
                if (s.empty()) {
                    ans += 1;
                    s.push('{');
                }
                else {
                    s.pop();
                }
            }
            else {
                s.push(ch);
            }
        }
        ans += s.size() / 2;
        cout << tc << '.' << ' ' << ans << '\n';
    }
}