#include <iostream>
#include <string>
using namespace std;
int mins(string s) {
	int len = s.length();
	int ans = 0;
	for (int i = 0; i < len; ++i) {
		ans *= 10;
		if (s[i] == '6') {
			ans += 5;
		}
		else {
			ans += (s[i] - '0');
		}
	}
	return ans;
}
int maxs(string s) {
	int len = s.length();
	int ans = 0;
	for (int i = 0; i < len; ++i) {
		ans *= 10;
		if (s[i] == '5') {
			ans += 6;
		}
		else {
			ans += (s[i] - '0');
		}
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	string  a, b;
	cin >> a >> b;
	cout << mins(a) + mins(b) << ' ' << maxs(a) + maxs(b);
	return 0;
}
