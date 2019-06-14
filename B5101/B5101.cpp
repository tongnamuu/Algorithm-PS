#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int a, b, c;
	while (true) {
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0) break;
		if ((c - a) % b == 0) cout << (c - a) / b + 1 << '\n';
		else cout << 'X' << '\n';
	}
}