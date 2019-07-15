#include <iostream>
#include <stack>
using namespace std;
int n;
int a[1000001];
int d[1000001];
int ans[1000001];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n; for (int i = 1; i <= n; ++i) { cin >> a[i]; d[a[i]] += 1; ans[i] = -1; }
	stack<pair<int, int>>s;
	for (int i = 1; i <= n; ++i) {
		while (!s.empty() && d[a[i]] > d[s.top().first]) {
			ans[s.top().second] = a[i];
			s.pop();
		}
		s.push({ a[i],i });
	}
	for (int i = 1; i <= n; ++i) cout << ans[i] << ' ';
}