#include <iostream>
using namespace std;
int main() {
	int n, t; cin >> n >> t;
	int r = t % (4 * n - 2);
	if (r <= 2 * n) cout << r;
	else cout << 4 * n - r;
}