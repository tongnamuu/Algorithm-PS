#include <iostream>
using namespace std;
int main() {
	int n; cin >> n; --n;
	int finger = n % 4;
	int direction = (n / 4) & 1;
	if (direction == 1) {
		cout << 5 - finger << '\n';
	}
	else if (direction == 0) {
		cout << finger + 1 << '\n';
	}
}