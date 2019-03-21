#include <iostream>
#include <memory.h>
using namespace std;
int n;
double a[16][16];
double d[16][1 << 16];
double max(const double &a, const double &b)
{
	if (a > b) return a;
	else return b;
}
double go(int length, unsigned int visit, int x)
{
	double &temp = d[x][visit];
	if (temp != 0) return temp;
	visit |= 1 << x;
	if (visit == (1 << n) - 1) return a[length][x];

	for (int i = 0; i < n; i++)
	{
		if ((visit >> i) & 1) continue;
		temp = max(temp, a[length][x] * go(length + 1, visit, i));
	}
	visit &= ~(1 << x);
	return temp;
}
int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		cin >> n;
		memset(d, 0, sizeof(d));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> a[i][j];
				a[i][j] /= 100.0;
			}
		}
		double ans = 0;
		for (int i = 0; i < n; i++)
			ans = max(ans, go(0, 0, i));
		cout << fixed;
		cout.precision(6);
		cout << '#' << test_case << ' ' << ans * 100.0 << '\n';
	}
	return 0;
}