#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
string remove_question_with_arg(const string& s, char c) {
    int len = s.length();
    string temp;
    bool find = false;
    for (int i = 0; i < len; ++i) {
        if (!find && s[i] == '0') continue;
        if (s[i] == '?') {
            if (c == '1') {
                temp += '1';
                find = true;
            }
            else {
                if (find) temp += '0';
            }
        }
        else if (s[i] == '1') {
            temp += '1';
            find = true;
        }
        else if (s[i] == '0') {
            if (find) temp += '0';
        }
    }
    return temp;
}
int calculate(int n, string& s) {
    int len = s.length();
    int cnt = 0;
    for (int i = 0; i < len; ++i) {
        if (s[i] == '1') ++cnt;
    }
    if (cnt > 1) return n + len;
    else if (cnt == 1) return n + len - 1;
    else return 1;
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; string s;
        cin >> n >> s;
        string x = remove_question_with_arg(s, '1');
        string y = remove_question_with_arg(s, '0');
        cout << calculate(n, x) << ' ' << calculate(n, y) << '\n';
    }
}
