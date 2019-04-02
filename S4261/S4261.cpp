#include <iostream>
#include <string>
using namespace std;
const char alp[] = { '2','2','2','3','3','3','4','4','4','5','5','5','6','6','6','7','7','7','7','8','8','8','9','9','9','9' };
string tonum(const string& a) {
	string temp;
	for(int i=0;a[i];++i) temp+=alp[a[i] - 'a'];
	return temp;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case) {
		string s; cin >> s;
		int n; cin >> n;
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			string p;cin >> p;
			string temp = tonum(p);
			if (temp == s) ++ans;
		}
		cout << '#' << test_case << ' ' << ans << '\n';
	}
}