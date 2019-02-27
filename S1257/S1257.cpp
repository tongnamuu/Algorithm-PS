#include <iostream>
#include <string>
#include <set>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case) {
		int k; cin >> k;
		string s; cin >> s;
		set<string> st;
		int len = s.length();
		for (int i = 0; i < len; ++i) {
			for (int j = i ;j < len;++j){
				string temp;
				for (int x = i; x <= j; ++x) {
					temp += s[x];
				}
				st.insert(temp);
			}
		}
		int cnt = 1;
		bool go = false;
		for (auto p : st) {
			if (cnt == k) {
				cout << '#' << test_case << ' ' << p << '\n';
				go = true;
				break;
			}
			cnt++;
		}
		if (!go) cout << '#' << test_case << ' ' << "none" << '\n';
	}
}