#include <iostream>
#include <string>
using namespace std;
bool isP(const string& s, int i, int j) {
    while (i < j) {
        if (s[i] != s[j]) return false;
        i++; j--;
    }
    return true;
}
bool isP1(const string& s) {
    int i = 0, j = s.length() - 1;
    while (i < j) {
        if (s[i] == s[j]){
            i++;
            j--;
        }
        else {
            if (isP(s, i, j - 1)) return true;
            else if (isP(s, i + 1, j)) return true;
            return false;
        }
    }
    return false;
}
int solve(const string& s) {
    if (isP(s, 0, s.length() - 1)) return 0;
    if (isP1(s)) return 1;
    return 2;
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n; cin >> n;
    string s;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        cout << solve(s) << '\n';
    }
}
