#include <iostream>
using namespace std;
int abs(int x, int y) {
	return x > y ? x - y : y - x;
}
int main() {
	int x, y; cin >> x >> y;
	int dx = 1;
	int cnt = 0;
	if (x < y) {
		int next = -1;
		int prev = x;
		while (next < y) {
			next = x + dx;
			dx *= -2;
			cnt += abs(prev, next);
			prev = next;
		}
		cnt -= (next - y);
	}
	else {
		int next = 1001;
		int prev = x;
		while (next > y) {
			next = x + dx;
			dx *= -2;
			cnt += abs(prev, next);
			prev = next;
		}
		cnt -= (y - next);
	}
	cout << cnt << '\n';
}