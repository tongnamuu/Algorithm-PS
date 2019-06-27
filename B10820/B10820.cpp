#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	string s;
	int small, cap, num, space;
	while (getline(cin, s)) {
		small = 0, cap = 0, num = 0, space = 0;
		for (int i = 0; s[i]; ++i) {
			if (s[i] >= 'A'&&s[i] <= 'Z') cap++;
			else if (s[i] >= 'a'&&s[i] <= 'z') small++;
			else if (s[i] <= '9' &&s[i] >= '0') num++;
			else if (s[i] == ' ') space++;
		}
		cout << small << ' ' << cap << ' ' << num << ' ' << space << '\n';
	}
}