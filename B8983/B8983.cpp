#include <iostream>
#include <algorithm>
using namespace std;
int a[100001];
pair<int, int > b[100001];
int l;
int abs(int x, int y) {
	if (x > y) return x - y;
	else return y - x;
}
bool ok(pair<int, int> s, int t) {
	if (abs(s.first, t) + s.second <= l) return true;
	else return false;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int ans = 0, m, n; cin >> m >> n >> l;
	for (int i = 0; i < m; ++i) cin >> a[i];
	for (int i = 0; i < n; ++i) cin >> b[i].first >> b[i].second;
	sort(a, a + m), sort(b, b + n);
	for (int i = 0; i < n; ++i) {
		int temp = b[i].first;
		int index = upper_bound(a, a + m, temp) - a;
		if (index<m && ok(b[i], a[index])) ans++;	
		else if(index-1>=0 && ok(b[i],a[index-1]))ans++;	
	}
	cout << ans << '\n';
}