#include <iostream>
#include <string>
using namespace std;
int main() {
	string s; cin >> s;
	int len = s.length();
	int ans = s[0] == 'd' ? 10 : 26;
	for (int i = 1; i < len; ++i) {
		int temp = s[i] == 'd' ? 10 : 26;
		if (s[i] == s[i - 1]) {
			temp--;
		}
		ans *= temp;
	}
	cout << ans << '\n';
}