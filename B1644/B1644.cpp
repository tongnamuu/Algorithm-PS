#include <iostream>
#include <vector>
using namespace std;
bool check[4000001];
vector<int>a;
int main() {
	int n; cin >> n;
	for (int i = 2; i <= n; ++i) {
		if (check[i]) continue;
		a.push_back(i);
		for (int j = i + i; j <= n; j += i) {
			check[j] = true;
		}
	}
	int ans = 0;
	int i = 0, j = 0;
	int sum = 0;
	if (!a.empty()) {
		sum = a[0];
		while (i < a.size() && j < a.size() && i <= j) {
			if (sum == n) {
				++ans;
				j++;
				if (j < a.size()) sum += a[j];
			}
			else if (sum > n) {
				sum -= a[i];
				i++;
			}
			else if (sum < n) {
				j++;
				if (j < a.size()) sum += a[j];
			}
		}
	}
	cout << ans << '\n';
}