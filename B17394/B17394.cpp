#include <iostream>
#include <queue>
using namespace std;
int n, A, B;
bool check[1000001];
int d[1000001];
bool solve(int num) {
	if (A <= num && num <= B && !check[num]) return true;
	return false;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	check[0] = check[1] = true;
	for (int i = 2; i <= 1000000; ++i) {
		if (check[i]) continue;
		for (int j = i + i; j <= 1000000; j += i) check[j] = true;
	}
	int T; cin >> T;
	while (T--) {
		cin >> n >> A >> B;
		for (int i = 0; i <= 1000000; ++i) d[i] = -1;
		queue<int>q;
		q.push(n);
		d[n] = 0;
		bool find = false;
		while (!q.empty()) {
			int now = q.front();
			q.pop();
			if (solve(now)) {
				cout << d[now] << '\n';
				find = true;
				break;
			}
			if (d[now / 2] == -1) {
				d[now / 2] = d[now] + 1;
				q.push(now / 2);
			}
			if (d[now / 3] == -1) {
				d[now / 3] = d[now] + 1;
				q.push(now / 3);
			}
			if (d[now - 1] == -1) {
				d[now - 1] = d[now] + 1;
				q.push(now - 1);
			}
			if (now+1 <= 1000000 && d[now + 1] == -1) {
				d[now + 1] = d[now] + 1;
				q.push(now + 1);
			}
		}
		if (!find) cout << -1 << '\n';
	}

}