#include <iostream>
#include <stack>
#include <memory.h>
using namespace std;
int d[1000001];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	memset(d, -1, sizeof(d));
	int n, num; cin >> n;
	stack<pair<int, int>>s; cin >> num; s.push({ num,0 });
	for (int i = 1; i < n; ++i) {
		cin >> num;
		while (!s.empty() && num > s.top().first) {
			d[s.top().second] = num;
			s.pop();
		}
		s.push({ num,i });
	}
	for (int i = 0; i < n; ++i) cout << d[i] << ' ';
}