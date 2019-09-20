struct Trie {
	int children[26];
	int cnt;
};
Trie trie[1600001];
int nodeCnt;
void initialize(int x) {
	for (register int i = 0; i < 26; ++i) trie[x].children[i] = -1;
	trie[x].cnt = 0;
}
int nextNode() {
	initialize(++nodeCnt);
	return nodeCnt;
}
void add(int node, char* str) {
	if (*str == 0) {
		return;
	}
	int next = *str - 'a';
	int& nextnode = trie[node].children[next];
	if (nextnode == -1) nextnode = nextNode();
	trie[nextnode].cnt++;
	add(nextnode, str + 1);
}

int find(int node, char* str) {
	if (*str == 0) {
		return trie[node].cnt;
	}
	int nextnode = trie[node].children[*str - 'a'];
	if (nextnode == -1) return 0;
	return find(nextnode, str + 1);
}

void init(void) {
	nodeCnt = 0;
	initialize(0);
}

void insert(int buffer_size, char *buf) {
	add(0, buf);
}

int query(int buffer_size, char *buf) {
	return find(0, buf);
}
