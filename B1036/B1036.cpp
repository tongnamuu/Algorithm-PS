#include <iostream>
#define DEBUG 0
using namespace std;
char a[51][51];
int cnt[52][37];
int LengthOfInpt[51];
bool selected[37];
int ans[53];
int my_strlen(char* str) {
	int len = 0;
	for (; str[len]; ++len);
	return len;
}
int ToDec(char a) {
	if (a <= '9'&&a >= '0') return a - '0';
	return a - 'A' + 10;
}
char DecToCharFor36(int x) {
	if (x >= 0 && x <= 9) return x + '0';
	return (char)(x - 10 + 'A');
}
long double powOf36(int x) {
	long double val = 1;
	long double temp = 36;
	while (x) {
		if (x & 1) {
			val *= temp;
		}
		temp *= temp;
		x >>= 1;
	}
	return val;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		int len = my_strlen(a[i]);
		LengthOfInpt[i] = len;
		for (int j = 0; j < len; ++j) {
			cnt[len - j - 1][ToDec(a[i][j])]++;
		}
	}
	int k; cin >> k;
	while (k--) {
		long double max_value = 0;
		int target = -1;
		for (int j = 0; j < 35; ++j) {
			if (selected[j]) continue;
			long double temp = 0;
			for (int i = 50; i >= 0; --i) {
				if (cnt[i][j]) {//i번째 자리가 j인 것의 개수, 바뀔 수 있는 것의 개수
					temp += powOf36(i)*cnt[i][j] * (35 - j);
				}
			}
			if (DEBUG) if(temp>0) cout << DecToCharFor36(j) << ' ' << temp << '\n';
			if (temp > max_value) {
				max_value = temp;
				target = j;
			}
		}
		if (target == -1) break;
		selected[target] = true;
		for (int i = 50; i >= 0; --i) {
			if (!cnt[i][target]) continue;
			cnt[i][35] += cnt[i][target];
			cnt[i][target] = 0;
		}
		if(DEBUG) cout << "changed character : " << DecToCharFor36(target) << '\n';
	}
	for (int i = 0; i <= 50; ++i) {
		int temp = 0;
		for (int j = 0; j < 36; ++j) {
			if (cnt[i][j]) {
				temp += cnt[i][j] * j;
			}
		}
		int r = ans[i] + temp;
		ans[i] = r % 36;
		ans[i + 1] = r / 36;
	}
	bool print = false;
	for (int i = 52; i >= 0; --i) {
		if (ans[i] > 0) print = true;
		if (print)cout << DecToCharFor36(ans[i]);
	}
	if (!print) cout << 0;
}