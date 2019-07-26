#include <iostream>
using namespace std;
struct maxheap {
	int heap[100001];
	int hsize = 0;
	void push(int x) {
		int i = ++hsize;
		for (; i > 1 && heap[i / 2] < x; i /= 2) heap[i] = heap[i / 2];
		heap[i] = x;
	}
	int top() { return hsize == 0 ? 0 : heap[1]; }
	void pop() {
		if (hsize == 0) return;
		int parent = 1, child = 2;
		int temp = heap[hsize];
		while (child < hsize) {
			if (child + 1 < hsize && heap[child] < heap[child + 1]) ++child;
			if (temp > heap[child]) break;
			heap[parent] = heap[child];
			parent = child;
			child *= 2;
		}
		heap[parent] = temp;
		--hsize;
	}
	int size() { return hsize; }
};
struct minheap {
	int heap[100001];
	int hsize = 0;
	void push(int x) {
		int i = ++hsize;
		for (; i > 1 && heap[i / 2] > x; i /= 2) heap[i] = heap[i / 2];
		heap[i] = x;
	}

	int top() { return hsize == 0 ? 0 : heap[1]; }
	void pop() {
		if (hsize == 0) return;
		int parent = 1, child = 2;
		int temp = heap[hsize];
		while (child < hsize) {
			if (child + 1 < hsize && heap[child] > heap[child + 1]) ++child;
			if (temp < heap[child]) break;
			heap[parent] = heap[child];
			parent = child;
			child *= 2;
		}
		heap[parent] = temp;
		--hsize;
	}
	int size() { return hsize; }
};
maxheap leftn;
minheap rightn;
void push(int data) {
	if (leftn.size() == 0) {
		leftn.push(data);
		return;
	}
	if (leftn.size() == rightn.size()) {
		if (data < rightn.top()) leftn.push(data);
		else {
			leftn.push(rightn.top());
			rightn.pop();
			rightn.push(data);
		}
	}
	else if (leftn.size() > rightn.size()) {
		if (leftn.top() > data) {
			rightn.push(leftn.top());
			leftn.pop();
			leftn.push(data);
		}
		else rightn.push(data);
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 0, num; i < n; ++i) {
		cin >> num;
		push(num);
		cout << leftn.top() << '\n';
	}
}