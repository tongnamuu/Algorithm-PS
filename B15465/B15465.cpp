#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int tonum(const string& s) {
	int num = 0;
	int len = s.length();
	for (int i = 0; i < len; ++i) {
		num *= 10;
		num += (s[i] - '0');
	}
	return num;
}
struct milk {
	int day;
	string name;
	string cmd;
	int change;
	bool operator<(const milk& a) const {
		return this->day < a.day;
	}
};
milk a[101];
int cow[3] = { 7,7,7 };
bool display[3] = { true, true,true };
int cmax = 7;
int ans = 0;
bool displaychange() {
	bool ch = false;
	for (int i = 0; i < 3; ++i) {
		if (cow[i] >= cmax) {
			if (display[i] == false) {
				ch = true;
			}
			display[i] = true;
		}
		else if (cow[i] < cmax) {
			if (display[i] == true) {
				ch = true;
			}
			display[i] = false;
		}
	}
	return ch;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i].day >> a[i].name >> a[i].cmd;
		string temp = a[i].cmd.substr(1);
		if (a[i].cmd[0] == '+') {
			a[i].change = tonum(temp);
		}
		else a[i].change = -tonum(temp);
	}
	sort(a, a + n);
	for (int i = 0; i < n; ++i) {
		if (a[i].name == "Bessie") {
			cow[0] += a[i].change;
		}
		else if (a[i].name == "Elsie") {
			cow[1] += a[i].change;
		}
		else if (a[i].name == "Mildred") {
			cow[2] += a[i].change;
		}
		cmax = max({ cow[0],cow[1],cow[2] });
		ans += displaychange();
	}
	cout << ans << '\n';
}