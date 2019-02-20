#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case) {
		string s;
		cin >> s;
		int len = s.length();
		int p = 1;
		for (p = 1; p <= 10; ++p) {
			bool find = true;
			string temp = "";
			for (int i = 0; i < p; ++i) {
				temp += s[i];
			}
			int index = 0;
			while (index+p < len) {
				for (int i = 0; i < p; ++i) {
					if (s[index + i] != temp[i]) {
						find = false;
						index = len;
						break;
					}
				}
				index += p;
			}
			if (find) {
				cout << '#' << test_case << ' ' << temp.length() << '\n';
				break;
			}
		}
	}
}