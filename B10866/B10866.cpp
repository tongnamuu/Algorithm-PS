#include <iostream>
#include <string>
using namespace std;
int a[30001];
int front = 10001;
int rear = 10001;
int dsize = 0;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	string cmd; int x;
	for (int i = 0; i < n; ++i) {
		cin >> cmd;
		if (cmd == "push_back") {
			cin >> x;
			a[rear++] = x;
			++dsize;
		}
		else if (cmd == "push_front") {
			cin >> x;
			a[--front] = x;
			++dsize;
		}
		else if (cmd == "front") {
			if (dsize>0) cout << a[front] << '\n';
			else cout << -1 << '\n';
		}
		else if (cmd == "back") {
			if(dsize>0) cout << a[rear-1] << '\n';
			else cout << -1 << '\n';
		}
		else if (cmd == "size") {
			cout << dsize << '\n';
		}
		else if (cmd == "pop_front") {
			if (dsize == 0) cout << -1 << '\n';
			else {
				cout << a[front++] << '\n';
				--dsize;
			}
		}
		else if (cmd == "pop_back") {
			if (dsize == 0) cout << -1 << '\n';
			else {
				cout << a[rear---1] << '\n';
				--dsize;
			}
		}
		else if (cmd == "empty") {
			cout << !dsize << '\n';
		}
	}
}