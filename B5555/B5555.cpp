#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	string p; cin >> p;
	int len = p.length();
	int n; cin >> n;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		string s; cin >> s;
		s += s;
		for (int j = 0; s[j]; ++j) {
			if (!s[j + len]) break;
			string temp = s.substr(j, len);
			if (temp == p) {
				++ans;
				break;
			}
		}
	}
	cout << ans << '\n';
}