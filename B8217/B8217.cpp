#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define SIZE 300001
vector<int> owner[SIZE];
vector<int>check[SIZE];
int goals[SIZE];
int qleft[SIZE];
int qright[SIZE];
int amount[SIZE];
int l[SIZE];
int r[SIZE];
int ans[SIZE];

long long BIT[SIZE];
void init(int N) {
	fill(BIT, BIT+N+1, 0);
}
long long sum(int index) {
	long long ans = 0LL;
	for (int i = index; i > 0; i -= i & -i) {
		ans += BIT[i];
	}
	return ans;
}
void update(int index, int N, long long diff) {
	for (int i = index; i <= N; i += i & -i) {
		BIT[i] += diff;
	}
}
void range_update(int s, int e, int N, long long diff) {
	update(s, N, diff);
	update(e + 1, N, -diff);
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int N, M; cin >> N >> M;
	for (int i = 1; i <= M; ++i) {
		int x; cin >> x;
		owner[x].push_back(i);
	}
	for (int i = 1; i <= N; ++i) {
		cin >> goals[i];
	}
	int q; cin >> q;
	for (int i = 1; i <= q; ++i) {
		cin >> qleft[i] >> qright[i] >> amount[i];
	}
	for (int i = 1; i <= N; ++i) {
		l[i] = 1;
		r[i] = q;
		ans[i] = -1;
	}

	while (true) {
		bool go = true;
		init(M + 1);
		for (int i = 1; i <= N; ++i) {
			if (l[i] <= r[i]) {
				check[(l[i] + r[i]) / 2].push_back(i);
				go = false;
			}
		}
		if (go) break;
		for (int i = 1; i <= q; ++i) {
			if (qleft[i] <= qright[i]) {
				range_update(qleft[i], qright[i], M + 1, amount[i]);
			}
			else {
				range_update(1, qright[i], M + 1, amount[i]);
				range_update(qleft[i], M, M + 1, amount[i]);
			}
			if (check[i].empty()) continue;
			for (int country : check[i]) {
				long long cnt = 0;
				for (int x : owner[country]) {
					cnt += sum(x); 
					if (cnt >= goals[country]) break;
				}
				if (cnt >= goals[country]) {
					ans[country] = i;
					r[country] = i - 1;
				}
				else {
					l[country] = i + 1;
				}
			}
			check[i].clear();
		}
	}
	for (int i = 1; i <= N; ++i) {
		if (ans[i] == -1) {
			cout << "NIE" << '\n';
		}
		else cout << ans[i] << '\n';
	}
}