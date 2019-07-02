#include <iostream>
#include <queue>
using namespace std;
int from[1000001];
int d[1000001];
void print(int n) {
	if (n != from[n]) print(from[n]);
	cout << n << ' ';
}
int main() {
	int n; cin >> n;
	queue<int>q;
	q.push(n);
	d[n] = 1;
	from[n] = n;
	while (!q.empty()) {
		int now = q.front(); q.pop();
		if (now % 3 == 0 && d[now / 3]==0) {
			q.push(now / 3);
			from[now / 3] = now;
			d[now / 3] = d[now] + 1;
		}
		if (now % 2 == 0 && d[now / 2] == 0) {
			q.push(now / 2);
			from[now / 2] = now;
			d[now / 2] = d[now] + 1;
		}
		if (now - 1 >= 1 && d[now - 1] == 0) {
			q.push(now - 1);
			from[now - 1] = now;
			d[now - 1] = d[now] + 1;
		}
	}
	cout << d[1] - 1 << '\n';
	print(1);
}