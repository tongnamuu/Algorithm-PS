#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	char s[71];
	while (true) {
		cin >> s;
		if (s[0] == '#') break;
		int len = 0;
		int y = 0, n = 0, p = 0, a = 0;
		for (; s[len]; ++len) {
			if (s[len] == 'Y') y++;
			else if (s[len] == 'N') n++;
			else if (s[len] == 'P') p++;
			else if (s[len] == 'A') a++;
		}
		if (a >= (len+1) / 2) cout << "need quorum" << '\n';
		else if (y > n) cout << "yes" << '\n';
		else if (n > y) cout << "no" << '\n';
		else if (y == n) cout << "tie" << '\n';
	}
}