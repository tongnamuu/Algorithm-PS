#include <iostream>
#include <deque>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	deque<int>q;
	int n, k; cin >> n >> k;
	for (int i = 1; i <= n; ++i) q.push_back(i);
	int ans = 0;
	for (int i = 0, num; i < k; ++i) {
		cin >> num;
		int cnt = 0;
		for (int number : q) {
			if (number == num) break;
			++cnt;
		}
		if (cnt > q.size() / 2) {
			while (q.front() != num) {
				int now = q.back();
				q.pop_back();
				q.push_front(now);
				++ans;
			}
			q.pop_front();
		}
		else {
			while (q.front() != num) {
				int now = q.front();
				q.pop_front();
				q.push_back(now);
				++ans;
			}
			q.pop_front();
		}
	}
	cout << ans << '\n';
}