#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int getscore(int x, int y) {
	if (x == y) return x + 10;
	else return (x + y) % 10;
}
int card[11];
int p[] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1 };
vector<int>cards;
int main() {
	int a, b; cin >> a >> b;
	int score = getscore(a, b);
	for (int i = 1; i <= 10; ++i) {
		card[i] = 2;
	}
	card[a]--; card[b]--;
	for (int i = 1; i <= 10; ++i) {
		for (int j = 0; j < card[i]; ++j) {
			cards.push_back(i);
		}
	}
	int cnt = 0;
	do {
		a = -1, b = -1;
		for (int i = 0; i < 18; ++i) {
			if (p[i]) {
				if (a == -1) a = i;
				else b = i;
			}
		}
		cnt += (score > getscore(cards[a], cards[b]));
	} while (next_permutation(p, p + 18));
	cout << fixed;
	cout.precision(3);
	cout << (double)cnt * 2 / 18 / 17 << '\n';
}