#include <iostream>
#include <queue>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	long long n, num; cin >> n;
	priority_queue<long long>q;
	for (int i = 0; i < n*n; ++i) {
		cin >> num;
		if (q.size() < n) q.push(-num);
		else {
			if (-q.top() < num) {
				q.pop();
				q.push(-num);
			}
		}
	}
	cout << -q.top() << '\n';
}