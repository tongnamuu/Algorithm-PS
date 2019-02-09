#include <iostream>
#include <queue>
using namespace std;
int d[100000] = { 0, };
int get(int num) {
	num <<= 1;
	int a[6];
	int c = 0;
	int ans = 0;
	while (num) {
		a[c++] = num % 10;
		num /= 10;
	}
	a[c - 1]--;
	for (int i = c - 1; i >= 0; --i) {
		ans *= 10;
		ans += a[i];
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, t, g;
	cin >> n >> t >> g;
	bool go = true;
	queue<int>q;
	q.push(n);
	d[n] = 1;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		int next = now + 1;
		if (0 <= next && next<=99999 && d[next]==0) {
			q.push(next);
			d[next] = d[now]+1;
		}
		if (now == 0) continue;
		if (now * 2 > 99999) continue;
		next = get(now);
		if (0 <= next && next <= 99999 && d[next] == 0) {
			q.push(next);
			d[next] = d[now] + 1;
		}
	}
	if (--d[g] > t) cout << "ANG" << '\n';
	else if(d[g]==-1) cout << "ANG" << '\n';
	else cout << d[g] << '\n';
}