#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	string s[1001];
	cin >> s[0];
	int n = s[0].length();
	for (int i = 1; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			s[i] += s[0][j];
		}
	}
	sort(s, s + n);
	for (int i = 0; i < n; ++i) cout << s[i] << '\n';
}