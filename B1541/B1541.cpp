#include <iostream>
#include <string>
using namespace std;
int getnum(string &s) {
	int ans = 0;
	for (int i = 0; s[i]; ++i) {
		ans *= 10;
		ans += (s[i] - '0');
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	string s; cin >> s;
	int len = s.length();
	int ans = 0;
	string temp = "";
	bool flag = false;
	bool num = true;
	int cmd = 1;
	for (int i = 0; i < len; ++i) {
		if ((s[i] == '-'|| s[i] == '+') && cmd==1 ) {
			ans += getnum(temp);
			temp = "";
		}
		else if ((s[i] == '-' || s[i] == '+') && cmd == 2) {
			ans -= getnum(temp);
			temp = "";
		}
		if (s[i] == '-') {
			cmd = 2;
			flag = true;
		}
		else if (!flag && s[i] == '+') {
			cmd = 1;
		}
		if (s[i] >= '0' && s[i] <= '9') {
			temp += s[i];
		}
	}
	if (flag) ans -= getnum(temp);
	else ans += getnum(temp);
	cout << ans << '\n';
}