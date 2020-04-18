#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define INF 2000000000
int a[1001];
int n, m;
int d[1001][201][21];
int go(int index, int rest, int prev) {
	if (index > n) return 0;
	int& ret = d[index][rest][prev];
	if (ret != -1) return ret;
	ret = INF;
	for (int spent = 0; spent <= 10; ++spent) {
		if (rest - spent < 0) break;
		if (a[index] + spent > 10) break;
		if (prev < a[index] + spent) {
			ret = min(ret, go(index + 1, rest - spent, a[index] + spent));
		}
		else {
			int temp = (prev - a[index] - spent)*(prev - a[index] - spent);
			ret = min(ret, go(index + 1, rest - spent, a[index] + spent) + temp);
		}
	}
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	memset(d, -1, sizeof(d));
	cout << go(1, m, 0);
}