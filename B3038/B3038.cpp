#include <iostream>
using namespace std;
int END;
int n;
void go(int val, int depth) {
	if (depth == END) {
		cout << 3 * depth - 1 - val << ' ';
		return;
	}
	cout << val << ' ';
	go(val + depth, depth << 1);
	go(val + (depth << 1), depth << 1);
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	END = 1 << (n - 1);
	go(1, 1);
}