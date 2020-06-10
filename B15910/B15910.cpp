#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define INF 1000000
char matching[8] = "#BANANA";
int d[100001][7];
string s;
char ans[100001];
int go(int n, int index, int state) {
    if (index == n - 1) {
        if (state == 6) return  s[index]=='A' ? 0 : 1;
        else return 10000000;
    }
    int& ret = d[index][state];
    if (ret != INF) return ret;
    int r = (matching[state] != s[index]) ? 1 : 0;
    ans[index] = matching[state];
    if (state == 1) {
        ret = min(ret, go(n, index + 1, 1) + r);
        ret = min(ret, go(n, index + 1, 2) + r);
    }
    else if (state == 2 || state == 3 || state == 4 || state == 5) {
        ret = min(ret, go(n, index + 1, state + 1) + r);
    }
    else if (state == 6) {
        ret = min(ret, go(n, index + 1, 1) + r);
        ret = min(ret, go(n, index + 1, 5) + r);
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> s;
    int n = s.length();
    for (int i = 0; i < n; ++i) {
        d[i][1] = d[i][2] = d[i][3] = d[i][4] = d[i][5] = d[i][6] = INF;
    }
    cout << go(n, 0, 1);
}