#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;
int n, k;
map<string, int>m;
vector<long long>ans;
void getmap(string s) {
	for (int j = 0; j < n; j += n / 4) {
		string temp;
		for (int i = j; i < j + n / 4; ++i) {
			temp += s[i];
		}
		m[temp]++;
	}
}
void getnum(string s) {
	reverse(s.begin(), s.end());
	int len = n/4;
	long long num = 0;
	for (int i = 0; i < len; ++i) {		
		if (s[i] == 'A') {
			num += 10 * (1 << (4 * i));
		}
		else if (s[i] == 'B') {
			num += 11 * (1 << (4 * i));
		}
		else if (s[i] == 'C') {
			num += 12 * (1 << (4 * i));
		}
		else if (s[i] == 'D') {
			num += 13 * (1 << (4 * i));
		}
		else if (s[i] == 'E') {
			num += 14 * (1 << (4 * i));
		}
		else if (s[i] == 'F') {
			num += 15 * (1 << (4 * i));
		}
		else {
			num += ((s[i] - '0')*(1 << (4 * i)));
		}
	}
	ans.push_back(num);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case) {
		ans.clear();
		m.clear();
		cin >> n >> k;
		string a;
		cin >> a;
		int rotate = n / 4;
		for (int i = 0; i < rotate; ++i) {
			string temp;
			temp += a[n - 1];
			for (int i = 0; i < n - 1; ++i) {
				temp += a[i];
			}
			getmap(temp);
			a = temp;
		}
		for (auto i = m.begin(); i != m.end(); ++i) {
			getnum(i->first);
		}
		sort(ans.begin(), ans.end());
		reverse(ans.begin(), ans.end());
		cout << '#'<<test_case<<' '<<ans[k-1] << '\n';
	}
}