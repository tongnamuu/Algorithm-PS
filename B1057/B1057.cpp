#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, a, b; cin >> n >> a >> b;
	int cnt = 1;
	while ((a + 1) / 2 != (b + 1) / 2) {
		a = (a + 1) / 2;
		b = (b + 1) / 2;
		++cnt;
	}
	cout << cnt << '\n';
}