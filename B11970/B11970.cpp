#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int a, b;
	int c, d;
	cin >> a >> b >> c >> d;
	int color[101] = { 0, };
	for (int i = a; i < b; ++i) color[i] = 1;
	for (int i = c; i < d; ++i) color[i] = 1;
	int ans = 0;
	for (int i = 0; i <= 100; ++i) ans += color[i];
	cout << ans << '\n';
}