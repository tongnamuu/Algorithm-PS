#include <iostream>
#include <cmath>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int a, b; cin >> a >> b;
	if (a*a == b) cout << -a;
	else {
		int x = int(sqrt(a*a - b));
		cout << -a - x << ' ' << -a + x;
	}
}