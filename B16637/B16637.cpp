#include <iostream>
#include <string>
using namespace std;
struct numop {
	int num;
	int operation;
};
numop a[20], b[20];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	string s; cin >> s;
	for (int i = 0; i < n; ++i) {
		if (s[i] >='0' && s[i]<='9') {
			a[i].num = s[i] - '0';
			a[i].operation = 0;
			b[i].num = s[i] - '0';
			b[i].operation = 0;
		}
		else {
			a[i].num = 0;
			if (s[i] == '+') {
				a[i].operation = 1;
				b[i].operation = 1;
			}
			else if (s[i] == '-') {
				a[i].operation = 2;
				b[i].operation = 2;
			}
			else if (s[i] == '*') {
				a[i].operation = 3;
				b[i].operation = 3;
			}
		}
	}
	int ans = -2147483648;
	int opcnt = (n - 1) / 2;
	for (int i = 0; i < (1 << opcnt); ++i) {
		bool go = true;
		for (int j = 0; j < opcnt - 1; ++j) {
			if (i&(1 << j) && i&(1 << (j + 1))) {
				go = false;
				break;
			}
		}
		if (!go) continue;
		for (int j = 0; j < n; ++j) {
			a[j].num = b[j].num;
			a[j].operation = b[j].operation;
		}
		for (int j = 0; j < opcnt; ++j) {
			if (i&(1 << j)) {
				int index = 2 * j + 1;
				if (a[index].operation == 1) {
					a[index - 1].num += a[index + 1].num;
					a[index].operation = 1;
					a[index + 1].num = 0;
				}
				else if (a[index].operation == 2) {
					a[index - 1].num -= a[index + 1].num;
					a[index].operation = 1;
					a[index + 1].num = 0;
				}
				else if (a[index].operation == 3) {
					a[index - 1].num *= a[index + 1].num;
					a[index].operation = 1;
					a[index + 1].num = 0;
				}
			}
		}
		int value = a[0].num;
		for (int j = 0; j < opcnt; ++j) {
			int k = 2 * j + 1;
			if (a[k].operation == 1) {
				value += a[k+1].num;
			}
			else if (a[k].operation == 2) {
				value -= a[k+1].num;
			}
			if (a[k].operation == 3) {
				value *= a[k+1].num;
			}
		}
		if (ans < value) {
			ans = value;
		}
	}
	cout << ans << '\n';
}