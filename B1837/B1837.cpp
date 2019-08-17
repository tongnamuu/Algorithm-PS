#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool check[1000001];
int a[101];
bool divide(int n, int size) {
	int val = 0;
	for (int i = 0; i < size; ++i) {
		val *= 10;
		val += a[i];
		val %= n;
	}
	return val == 0;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	string p;
	int k;
	cin >> p >> k;
	int len = p.length();
	for (int i = len - 1; i >= 0; --i) {
		a[i] = p[i] - '0';
	}
	vector<int>primes;
	check[0] = check[1] = true;
	for (int i = 2; i < k; ++i) {
		if (check[i]) continue;
		primes.push_back(i);
		for (int j = i + i; j < k; j += i) {
			check[j] = true;
		}
	}
	for (int i = 0; i < primes.size(); ++i) {
		if (divide(primes[i], len)) {
			cout << "BAD" << ' ' << primes[i] << '\n';
			return 0;
		}
	}
	cout << "GOOD" << '\n';
}