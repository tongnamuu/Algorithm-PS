#include <iostream>
#include <string>
bool check[26];
using namespace std;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	string s; cin >> s;
	int len = 0;
	for (; s[len]; ++len) check[s[len] - 'a'] = true;
	int index = -1;
	for (int i = 0; i < 26; ++i) {
		if (!check[i]) {
			index = i;
			break;
		}
	}
	if (index != -1) {
		cout << s + (char)(index + 'a') << '\n';
	}
	else {
		index = len - 1;
		while (index >= 1 && s[index - 1] >= s[index]) --index;
		if (index == 0) cout << -1 << '\n';
		else {
			int ind = len - 1;
			while (s[index - 1] >= s[ind]) --ind;
			char temp = s[ind];
			s[ind] = s[index - 1];
			s[index - 1] = temp;
			s = s.substr(0, index);
			cout << s << '\n';
		}
	}
}