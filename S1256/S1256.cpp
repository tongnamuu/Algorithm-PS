#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case) {
		int k; cin >> k;
		string s[400]; cin >> s[0];
		int len = s[0].length();
		for (int i = 0; i < len; ++i) s[i] = s[0].substr(i);
		sort(s, s + len);
		cout << '#' << test_case << ' ' << s[k - 1] << '\n';
	}
}