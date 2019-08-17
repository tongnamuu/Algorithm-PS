#include <iostream>
#include <algorithm>
using namespace std;
int a[51];
int main() {
	int n; cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];
	int N; cin >> N;
	sort(a, a + n);
	int index = lower_bound(a, a + n, N) - a;
	if (a[index] == N)  cout << 0 << '\n';
	else {
		int ans = 0;
		if (index == 0) {
			for (int i = 1; i <= N; ++i)
				for (int j = N; j < a[0]; ++j)
					if (i < j) ++ans;
		}
		else {
			for (int i = a[index - 1] + 1; i <= N; ++i)
				for (int j = N; j < a[index]; ++j)
					if (i < j)++ans;
		}
		cout << ans << '\n';
	}
}