#include <iostream>
#include <string>
using namespace std;
int toNum(const string& s) {
	int num = 0;
	int len = s.length();
	int minus = 1;
	int start = 0;
	if (s[0] == '-') {
		minus = -1;
		start = 1;
	}
	else if (s[0] == '+') {
		start = 1;
	}
	for (int i = start; i < len; ++i) {
		num *= 10;
		num += s[i] - '0';
	}
	return num*minus;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	string s; cin >> s;
	int len = s.length();
	int xpos = -1;
	string x_coeff;
	string Integer;
	for (int i = 0; i < len; ++i) {
		if (s[i] == 'x') {
			xpos = i;
			break;
		}
	}
	if (xpos == -1) {
		if (s[0] == '-') {
			cout << '-';
			Integer = s.substr(1);
		}
		else {
			Integer = s.substr(0);
		}
		int num = toNum(Integer);
		if (num == 0) cout << "W";
		else if(num == 1)cout << "x+W";
		else cout << toNum(Integer) << "x+W";
	}
	else {
		x_coeff = s.substr(0, xpos);
		Integer = s.substr(xpos + 1);
		int x_coeff_int = toNum(x_coeff)/2;
		int Integer_int = toNum(Integer);
		if (x_coeff_int == -1) cout << "-xx";
		else if (x_coeff_int == 1) cout << "xx";
		else cout << x_coeff_int << "xx";
		if (Integer_int < 0) {
			if (Integer_int == -1) {
				cout << "-x+W";
			}
			else {
				cout << Integer_int << "x+W";
			}
		}
		else if (Integer_int > 0) {
			if (Integer_int == 1) {
				cout << "+x+W";
			}
			else {
				cout << '+' << Integer_int << "x+W";
			}
		}
		else {
			cout << "+W";
		}
	}
}