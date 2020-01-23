#include <iostream>
using namespace std;
struct Trie {
	int children[10];
	int number;
};
Trie trieNodePool[100000 * 8];
int nodeCnt;

int nextNode() {
	++nodeCnt;
	for (int i = 0; i < 10; ++i) {
		trieNodePool[nodeCnt].children[i] = -1;
	}
	trieNodePool[nodeCnt].number = -1;
	return nodeCnt;
}

int NumberOfStudnet = 0;
int insert(int node, char* str) {
	if (*str == 0) {
		if (trieNodePool[node].number == -1) {
			++NumberOfStudnet;
			trieNodePool[node].number = NumberOfStudnet;
			return NumberOfStudnet;
		}
		else {
			++NumberOfStudnet;
			trieNodePool[node].number = NumberOfStudnet;
			return -1;
		}
	}
	int& nextnode = trieNodePool[node].children[*str - '0'];
	if (nextnode == -1) {
		nextnode = nextNode();
	}
	return insert(nextnode, str + 1);
}

int find(int node, char* str) {
	if (node == -1)return -1;
	if (*str == 0) return trieNodePool[node].number;
	int nextnode = trieNodePool[node].children[*str - '0'];
	return find(nextnode, str + 1);
}

struct students {
	char id[9];
	int numbering;
};
bool cmp(const students& u, const students& v) {
	return u.numbering < v.numbering;
}
students studentlist[500001];
students temp[500001];
int sn;

void init(int& root) {
	nodeCnt = -1;
	sn = 0;
	root = nextNode();
}
int my_strcmp(char* a, char* b) {
	while (*a != 0) {
		if (*a != *b) break;
		a++; b++;
	}
	return *a - *b;
}
void my_strcpy(char* a, char* b) {
	int i;
	for (i = 0; b[i]; ++i) {
		a[i] = b[i];
	}
	a[i] = '\0';
}
void sort(int start, int end) {
	if (start == end) return;
	int mid = (start + end) / 2;
	sort(start, mid); sort(mid + 1, end);
	int i = start, j = mid + 1, k = 0;
	while (i <= mid && j <= end) {
		if (cmp(studentlist[i], studentlist[j])) temp[k++] = studentlist[i++];
		else temp[k++] = studentlist[j++];
	}
	while (i <= mid) temp[k++] = studentlist[i++];
	while (j <= end) temp[k++] = studentlist[j++];
	for (int s = start; s <= end; ++s) {
		studentlist[s] = temp[s - start];
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, k; cin >> k >> n;
	int root;
	init(root);
	for (int i = 1; i <= n; ++i) {
		char name[9];
		cin >> name;
		int temp = insert(root, name);
		if (temp == -1) continue;
		my_strcpy(studentlist[sn++].id, name);
	}
	for (int i = 0; i < sn; ++i) {
		studentlist[i].numbering = find(root, studentlist[i].id);
	}
	sort(0, sn - 1);
	k = k < sn ? k : sn;
	for (int i = 0; i < k; ++i) {
		cout << studentlist[i].id << '\n';
	}
}