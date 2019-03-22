#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	bool find = false;
	for (int i = 1; i <= 5; ++i) {
		string s; cin >> s;
		int len = s.length();
		for (int j = 0; j + 2 < len; ++j) {
			if (s[j] == 'F'&&s[j + 1] == 'B'&&s[j + 2] == 'I') {
				cout << i << ' ';
				find = true;
				break;
			}
		}
	}
	if (!find) cout << "HE GOT AWAY!" << '\n';
}