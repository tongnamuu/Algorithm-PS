#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 1000000000;
int min(int x, int y) { return x > y ? y : x; }
struct student {
	int exam1, exam2, exam3;
	bool operator<(const student& a) const {
		return this->exam1 < a.exam1;
	}
};
student a[500001];
int seg[2000001];
void init(int node, int start, int end) {
	seg[node] = INF;
	if (start != end) {
		init(node * 2, start, (start + end) / 2);
		init(node * 2 + 1, (start + end) / 2 + 1, end);
	}
}
void update(int node, int start, int end, int index, int val) {
	if (index > end || index < start) return;
	seg[node] = min(seg[node], val);
	if (start != end) {
		update(node * 2, start, (start + end) / 2, index, val);
		update(node * 2 + 1, (start + end) / 2 + 1, end, index, val);
	}
}
int query(int node, int start, int end, int i, int j) {
	if (i > end || j < start) return INF;
	else if (i <= start && end <= j) return seg[node];
	else return min(query(node * 2, start, (start + end) / 2, i, j), query(node * 2 + 1, (start + end) / 2 + 1, end, i, j));
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 1, num; i <= n; ++i) {
		cin >> num;
		a[num].exam1 = i;
	}
	for (int i = 1, num; i <= n; ++i) {
		cin >> num;
		a[num].exam2 = i;
	}for (int i = 1, num; i <= n; ++i) {
		cin >> num;
		a[num].exam3 = i;
	}
	sort(a + 1, a + n + 1);
	init(1, 1, n);
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		int score = query(1, 1, n, 1, a[i].exam2);
		if (score > a[i].exam3) ++ans;
		update(1, 1, n, a[i].exam2, a[i].exam3);
	}
	cout << ans << '\n';
}