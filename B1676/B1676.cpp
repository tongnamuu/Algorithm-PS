#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	int a = 0, b = 0;
	for (int i = 2; i <= n; i *= 2) a += n / i;
	for (int i = 5; i <= n; i *= 5) b += n / i;
	if (a > b) cout << b << '\n';
	else cout << a << '\n';
}