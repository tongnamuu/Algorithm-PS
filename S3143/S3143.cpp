#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case) {
		string s, p; cin >> s >> p;
		int n = s.length();
		int m = p.length();
		int i = 0;
		int ans = 0;
		while (i + m <= n) {
			string temp = s.substr(i, m);
			if (temp == p) {
				++ans;
				i += m;
			}
			else ++i;
		}
		cout << '#' << test_case << ' ' << n - ans * (m - 1) << '\n';
	}
}