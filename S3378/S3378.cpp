#include <iostream>
#include <string>
#include <set>
using namespace std;
char str[10][101];
char pat[10][101];
int p, n;
int prevcnt[10];
bool check(int r, int c, int s) {
	int x = 0, y = 0, z = 0;
	for (int i = 0; i + 1 < p; ++i) {
		for (int j = 0; str[i][j]; ++j) {
			if (str[i][j] == '(') ++x;
			else if (str[i][j] == ')') --x;
			else if (str[i][j] == '{') ++y;
			else if (str[i][j] == '}') --y;
			else if (str[i][j] == '[') ++z;
			else if (str[i][j] == ']') --z;
		}
		if (r*x + c * y + s * z != prevcnt[i + 1]) return false;
	}
	return true;
}
struct pos {
	int r, c, s;
	bool operator<(const pos& a) const {
		if (this->r == a.r) {
			if (this->c == a.c) {
				return this->s < a.s;
			}
			else return this->c < a.c;
		}
		else return this->r < a.r;
	}
};
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case) {
		cin >> p >> n;
		cin.ignore();
		for (int i = 0; i < p; ++i) {
			cin.getline(str[i], 101);
			prevcnt[i] = 0;
			for (int j = 0; str[i][j] == '.'; ++j) {
				++prevcnt[i];
			}
		}
		for (int i = 0; i < n; ++i) {
			cin.getline(pat[i], 101);
		}
		set<pos>hubo;
		int r = -1, c = -1, s = -1;
		for (int a = 1; a <= 20; ++a) {
			for (int b = 1; b <= 20; ++b) {
				for (int cc = 1; cc <= 20; ++cc) {
					if (check(a, b, cc)) {
						r = a;
						c = b;
						s = cc;
						hubo.insert({ a,b,cc });
					}
				}
			}
		}
		int anscnt[11] = { 0, };
		int x = 0, y = 0, z = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; pat[i][j]; ++j) {
				if (pat[i][j] == '(') ++x;
				else if (pat[i][j] == ')') --x;
				else if (pat[i][j] == '{') ++y;
				else if (pat[i][j] == '}') --y;
				else if (pat[i][j] == '[') ++z;
				else if (pat[i][j] == ']') --z;
			}
			set<int>ans;
			for (pos p : hubo) {
				ans.insert(x*p.r + y * p.c + z * p.s);
			}
			if (ans.size() == 1) {
				anscnt[i + 1] = *ans.begin();
			}
			else anscnt[i + 1] = -1;
		}
		cout << '#' << test_case << ' ';
		for (int i = 0; i < n; ++i) cout << anscnt[i] << ' ';
		cout << '\n';
	}
}