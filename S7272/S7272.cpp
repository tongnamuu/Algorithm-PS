#include <iostream>
#include <string>
using namespace std;
bool isSamechar(char a, char b) {
	if (a == 'B') {
		if(b=='B') return true;
		else return false;
	}
	else if (a == 'A' or a == 'D' or a == 'O' or a == 'P' or a == 'Q' or a == 'R') {
		if (b == 'A' or b == 'D' or b == 'O' or b == 'P' or b == 'Q' or b == 'R') {
			return true;
		}
		else return false;
	}
	else {
		if (b == 'A' or b == 'D' or b == 'O' or b == 'P' or b == 'Q' or b == 'R' or b == 'B') {
			return false;
		}
		else return true;
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case) {
		string a, b;
		cin >> a >> b;
		int lena = a.length();
		int lenb = b.length();
		if (lena != lenb) {
			cout << '#' << test_case << ' ' << "DIFF" << '\n';
		}
		else {
			bool same = true;
			for (int i = 0; i < lena; ++i) {
				if (!isSamechar(a[i], b[i])) {
					same = false;
					break;
				}
			}
			if(same) cout << '#' << test_case << ' ' << "SAME" << '\n';
			else cout << '#' << test_case << ' ' << "DIFF" << '\n';
		}
	}
}