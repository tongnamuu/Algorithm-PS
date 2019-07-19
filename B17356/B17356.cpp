#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int a, b; cin >> a >> b;
	double M = (double)(b - a) / 400;
	double ans = 1 / (1 + pow(10, M));
	cout << fixed;
	cout.precision(6);
	cout << ans << '\n';
}