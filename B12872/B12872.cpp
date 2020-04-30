#include <iostream>
using namespace std;
#define MOD 1000000007
long long d[101][101];
int n, m, p;
long long go(int index, int used) {
	if (index == p) {
		return used == n ? 1 : 0;
	}
	long long& ret = d[index][used];
	if (ret != -1) return ret;
	int not_used = n - used;
	ret = 0;
	if (used > m) {
		ret += go(index + 1, used)*(used - m);
		ret %= MOD;
	}
	if(not_used)
		ret += go(index + 1, used + 1)*not_used;
	return ret %= MOD;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m >> p;
	for (int i = 0; i <= p; ++i) {
		for (int j = 0; j <= n; ++j) {
			d[i][j] = -1;
		}
	}
	cout<<go(0, 0);
}