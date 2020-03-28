#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int card[400001];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m, k; cin >> n >> m >> k;
	for (int i = 0, x, y; i < m; ++i) {
		cin >> x >> y;
		card[x] = card[y] = 1;
	}
	int p1, p2; cin >> p1 >> p2;
	card[p1] = card[p2] = 1;
	int my_score = abs(p1%k - p2 % k);
	vector<int>cards;
	for (int i = 1; i <= 4 * n; ++i) {
		if (!card[i]) {
			cards.push_back(i%k);
		}
	}
	sort(cards.begin(), cards.end());
	int i = 0, j = 1;
	int ans = 0;
	while (i < cards.size() && j < cards.size()) {
		int temp = cards[j] - cards[i];
		if (temp > my_score) {
			ans++;
			i++;
			j++;
		}
		else {
			j++;
		}
	}
	cout << min(ans, m - 1);
}