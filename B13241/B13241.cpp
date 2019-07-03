#include <iostream>
using namespace std;
long long gcd(long long a, long long b) {
	while (b) {
		long long r = a % b;
		a = b;
		b = r;
	}
	return a;
}
int main() {
	long long a, b; cin >> a >> b; cout << a / gcd(a, b)*b << '\n';
}