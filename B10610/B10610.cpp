#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool cmp(const char &a, const char &b) {
	return a > b;
}
bool check(string &s) {
	int len = s.length();
	int temp = 0;
	bool find = false;
	for (int i = 0; i < len; ++i) {
		if (s[i] == '0') find = true;
		temp += s[i] - '0';
	}
	if (find&&temp % 3 == 0) return true;
	else return false;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	string n; cin >> n;
	if (check(n)) {
		sort(n.begin(), n.end(), cmp);
		cout << n << '\n';
	}
	else cout << -1 << '\n';
}