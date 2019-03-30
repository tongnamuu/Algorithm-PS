#include <iostream>
#include <string>
#include <memory.h>
using namespace std;
int n;
string s;
int d[1001];
char get_next(char now) {
	if (now == 'B') return 'O';
	if (now == 'O') return 'J';
	if (now == 'J') return 'B';
}
int go(int index) {
	if (index == n - 1) {
		return 0;
	}
	if (d[index] != -1) {
		return d[index];
	}
	char next = get_next(s[index]);
	int ans = -1;
	for (int j = index + 1; j < n; ++j) {
		if (s[j] == next) {
			int temp = go(j);
			if (temp == -1) continue;
			int val = (j - index)*(j - index) + temp;
			if (ans == -1 || ans > val) {
				ans = val;
			}
		}
	}
	d[index] = ans;
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	cin >> s;
	memset(d, -1, sizeof(d));
	cout << go(0) << '\n';
}