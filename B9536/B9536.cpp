#include <iostream>
#include <string>
using namespace std;
long long tonum(string s) {
	int len = s.length();
	long long num = 0;
	for (int i = 0; i < len; ++i) {
		num <<= 4;
		switch (s[i]) {
		case 'A':
			num += 10;
			break;
		case 'B':
			num += 11;
			break;
		case 'C':
			num += 12;
			break;
		case 'D':
			num += 13;
			break;
		case 'E':
			num += 14;
			break;
		case 'F':
			num += 15;
			break;
		default:
			num += (s[i] - '0');
			break;
		}
	}
	return num;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string a;
	cin >> a;
	cout << tonum(a);
}