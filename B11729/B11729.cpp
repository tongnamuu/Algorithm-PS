#include <iostream>
using namespace std;
void go(int start, int end, int n) {
	if (n == 1) {
		cout << start <<' '<< end << '\n';
		return;
	}
	int empty = 6 - start - end;
	go(start, empty, n - 1);
	cout << start << ' ' << end << '\n';
	go(empty, end, n - 1);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int s1 = 1;
	int s2 = 1;
	int t = n;
	while (--t) {
		s2 = 2 * s1 + 1;
		s1 = s2;
	}
	cout << s2 << '\n';
	go(1, 3, n);
}