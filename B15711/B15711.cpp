#include <iostream>
#include <vector>
using namespace std;
bool check[2000001];
vector<int>p;
bool isPrime(long long n) {
	for (int i = 0; i<p.size() && p[i] * p[i] <= n; ++i) {
		if (n%p[i] == 0) return false;
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	check[0] = check[1] = true;
	for (int i = 2; i <= 2000000; ++i) {
		if (!check[i]) {
			p.push_back(i);
			for (int j = i + i; j <= 2000000; j += i) check[j] = true;
		}
	}
	int T; cin >> T;
	long long a, b, temp;
	while (T--) {
		cin >> a >> b;
		temp = a + b;
		if (temp < 4) {
			cout << "NO" << '\n';
			continue;
		}
		if (temp % 2 == 0) {
			cout << "YES" << '\n';
			continue;
		}
		else {
			if (isPrime(temp - 2)) cout << "YES" << '\n';
			else cout << "NO" << '\n';
		}
	}
}