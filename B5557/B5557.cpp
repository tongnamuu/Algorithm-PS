#include <iostream>
using namespace std;
int a[101];
long long d[101][21];
int main() {
	int n; cin >> n; 
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	d[1][a[1]] = 1;
	for (int i = 2; i <= n; ++i) {
		for (int j = 0; j <= 20; ++j) {
			if(j-a[i]>=0) d[i][j] += d[i - 1][j - a[i]];
			if(j+a[i]<=20) d[i][j] += d[i - 1][j + a[i]];
		}
	}
	cout<<d[n - 1][a[n]];
}