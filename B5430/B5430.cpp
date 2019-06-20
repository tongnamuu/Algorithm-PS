#include <iostream>
#include <cstdio>
using namespace std;
char p[100001];
char s[1000000];
int a[100001];
int an = 0;
int n;
int front = 0, rear = 0;
int dir = 1;
int cnt = 0;
int tonum(char k[]) {
	int n = 0;
	for (int i = 0; k[i]; ++i) {
		n *= 10;
		n += (k[i] - '0');
	}
	return n;
}
void input() {
	int index = 0;
	char numaschar[5];
	for (int i = 1; s[i]; ++i) {
		if (s[i] == ']' || s[i] == ',') {
			numaschar[index] = NULL;
			a[an++] = tonum(numaschar);
			index = 0;
			continue;
		}
		numaschar[index++] = s[i];
	}
}
void print() {
	if (cnt>n) {
		printf("error\n");
		return;
	}
	if (front == rear||cnt==n) {
		printf("[]\n");
		return;
	}
	if (dir == 1) {
		printf("[");
		for (int i = front; i < rear-1; ++i) {
			printf("%d,", a[i]);
		}
		printf("%d]\n", a[rear-1]);
	}
	else {
		printf("[");
		for (int i = rear-1; i > front; --i) {
			printf("%d,", a[i]);
		}
		printf("%d]\n", a[front]);
	}
}
int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%s", p);
		scanf("%d", &n);
		scanf("%s", s);
		an = 0;
		cnt = 0;
		front = 0, rear = n;
		dir = 1;
		input();
		for (int i = 0; p[i]; ++i) {
			if (p[i] == 'R') {
				dir ^= 1;
			}
			else if (p[i] == 'D') {
				++cnt;
				if (dir == 1) {
					++front;
				}
				else {
					--rear;
				}
			}
		}
		print();
	}
}