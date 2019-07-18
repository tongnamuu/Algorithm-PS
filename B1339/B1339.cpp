#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
set<char>alp;
int mapping[26];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int n; cin >> n;
	vector<string>a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		for (int j = 0; a[i][j]; ++j) {
			alp.insert(a[i][j]);
		}
	}
	vector<int>d(alp.size());
	for (int i = 0; i < alp.size(); ++i) {
		d[i] = (9 - i);
	}
	sort(d.begin(), d.end());
	int ans = 0;
	do {
		int index = 0;
		for (char x : alp) {
			mapping[x - 'A'] = d[index++];
		}
		int temp = 0;
		for (int i = 0; i < n; ++i) {
			int cur = 0;
			for (int j = 0; a[i][j]; ++j) {
				cur *= 10;
				cur += mapping[a[i][j] - 'A'];
			}
			temp += cur;
		}
		if (temp > ans) ans = temp;
	} while (next_permutation(d.begin(), d.end()));
	cout << ans << '\n';
}