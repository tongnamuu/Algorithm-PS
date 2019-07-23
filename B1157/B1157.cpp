#include <iostream>
#include <string>
using namespace std;
int main() {
	string s; cin >> s;
	int d[26] = { 0, };
	for (int i = 0; s[i]; ++i) {
		if (s[i] >= 'A'&&s[i] <= 'Z') d[s[i] - 'A']++;
		else if (s[i] >= 'a'&&s[i] <= 'z') d[s[i] - 'a']++;
	}
	int ans = 0; int index = -1;
	for (int i = 0; i < 26; ++i) {
		if (d[i] > ans) {
			ans = d[i];
			index = i;
		}
	}
	for (int i = 0; i < 26; ++i) {
		if (d[i] == ans && i != index) {
			cout << '?' << '\n';
			return 0;
		}
	}
	cout << (char)('A' + index) << '\n';
}