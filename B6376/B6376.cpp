#include <iostream>
#include <cstdio>
using namespace std;
long double d[] = { 1, 1,2,6,24,120,720,720 * 7,720 * 7 * 8,720 * 7 * 8 * 9 };
int main() {
	cout << 'n' << ' ' << 'e' << '\n';
	cout << "- -----------"<< '\n';
	double e = 0.0;
	printf("0 1\n");
	printf("1 2\n");
	printf("2 2.5\n");
	for (int i = 0; i < 10; ++i) {
		e += 1 / d[i];
		if(i>2)printf("%d %.9f\n", i, e);
	}
}