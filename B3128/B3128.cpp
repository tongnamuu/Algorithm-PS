#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int used[26];
int dist_right(char x, char y) {
    if (x <= y) return y - x;
    return 26 - (x - y);
}
int dist_left(char x, char y) {
    if (x < y) return 26 - (y - x);
    return x - y;
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    string s; getline(cin, s);
    string temp;
    for (char c : s) {
        if (c >= 'A' && c <= 'Z') {
            if (!used[c - 'A']) {
                used[c - 'A'] = 1;
                temp += c;
            }
        }
    }
    sort(temp.begin(), temp.end());
    int n = temp.size();
    temp += temp;
    int ans = 2147483647;
    int idx = 0;
    for (int i = 0; i < n; ++i) {
        int val1 = min(dist_left('A', temp[i]), dist_right('A', temp[i])) + 1;
        for (int j = i + 1; j < i + n; ++j) {
            int dr = dist_right(temp[j-1], temp[j]);
            val1 += dr;
            val1 += 1;
        }
        if (ans > val1) {
            ans = val1;
            idx = i;
        }
    }
    reverse(temp.begin(), temp.end());
    bool reversed = false;
    for (int i = 0; i < n; ++i) {
        int val1 = min(dist_left('A', temp[i]), dist_right('A', temp[i])) + 1;
        for (int j = i + 1; j < i + n; ++j) {
            int dr = dist_left(temp[j-1], temp[j]);
            val1 += dr;
            val1 += 1;
        }
        if (ans > val1) {
            ans = val1;
            idx = i;
            reversed = true;
        }
    }
    cout << ans << '\n';
    if(reversed) cout << temp.substr(idx, n);
    else {
        reverse(temp.begin(), temp.end());
        cout << temp.substr(idx, n);
    }
}
