#include <iostream>
using namespace std;
int main() {
	long double a, b, r;
	cin >> a >> b >> r;
	if (b != 0) {
		long double c = (long double)r / b;
		if (a > c) cout << "overflow" << '\n';
		else printf("%.0Lf\n", a*b);
	}
	else cout << 0 << '\n';
}