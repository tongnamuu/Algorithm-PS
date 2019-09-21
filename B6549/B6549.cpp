#include <iostream>
#include <stack>
using namespace std;
long long a[100001];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	long long ans;
	long long num;
	while (true) {
		cin >> n;
		if (n == 0) break;
		stack<int>s;
		ans = 0;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			while (!s.empty() && a[s.top()] > a[i]) {
				long long width = i;
				long long height = a[s.top()];
				s.pop();
				if (!s.empty()) {
					width = i - 1 - s.top();
				}
				if (ans < (long long)height*width) ans = (long long)height*width;
			}
			s.push(i);
		}
		while (!s.empty()) {
			long long width = n;
			long long height = a[s.top()];
			s.pop();
			if (!s.empty()) {
				width = n - s.top() - 1;
			}
			if (ans < (long long)height*width) ans = (long long)height*width;
		}
		cout << ans << '\n';
	}
}