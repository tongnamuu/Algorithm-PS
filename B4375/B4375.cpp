#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	while (cin >> n) {
		int cnt = 1;
		int num = 1;
		while (num%n > 0) {
			num = num * 10 + 1;
			num %= n;
			++cnt;
		}
		cout << cnt << '\n';
	}
}