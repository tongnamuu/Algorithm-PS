#include <iostream>
using namespace std;
int min(int a, int b) { return a > b ? b : a; }
int main() {
	int x, y, w, h; cin >> x >> y >> w >> h;
	int ans = min(min(y, x), min(w - x, h - y));
	cout << ans << '\n';
}