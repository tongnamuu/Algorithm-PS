#include <iostream>
#include <string>
using namespace std;
string colors[] = { "black","brown","red","orange","yellow","green","blue","violet","grey","white" };
const long long v[10] = { 1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000 };

int getvalue(string a) {
	for (int i = 0; i < 10; ++i) {
		if (colors[i] == a) return i;
	}
}
long long getmultiple(string a) {
	for (int i = 0; i < 10; ++i) {
		if (colors[i] == a) return v[i];
	}
}
int main() {
	string color;
	long long ans = 0;
	for (int i = 0; i < 2; ++i) {
		cin >> color;
		ans *= 10;
		ans += getvalue(color);
	}
	cin >> color;
	ans *= getmultiple(color);
	cout << ans << '\n';
}