#include <iostream>
using namespace std;
int main() {
	long long n;
	int b;
	cin >> n >> b;
	long long k = (1LL << (b + 1)) - 1;
	if (k >= n) cout << "yes";
	else cout << "no";
}