#include <iostream>
#include <string>
using namespace std;
struct Node {
	string name="123";
	Node* next;
	Node* prev;
	void setName(string str) {
		this->name = str;
	}
};
Node nodePool[5000];
int nodeCnt = 0;
Node* newNode() { return &nodePool[nodeCnt++]; }
struct list {
	Node* head;
	Node* tail;
	int len;
	list() {
		head = newNode();
		tail = newNode();
		this->head->next = tail;
		this->tail->prev = head;
		len = 0;
	}
	void push_back(Node* node) {
		this->tail->prev->next = node;
		node->prev = this->tail->prev;
		node->next = this->tail;
		this->tail->prev = node;
		++len;
	}
	void print(int year) {
		Node* temp = this->head->next;
		while (temp != this->tail) {
			cout << year << ' ' << temp->name << '\n';
			temp = temp->next;
		}
	}
};
list a[2017];
void init() {
	Node* temp = &nodePool[nodeCnt++];
	temp->setName("DavidBowie");
	a[1967].push_back(temp);

	Node* temp1 = &nodePool[nodeCnt++];
	temp1->setName("SpaceOddity");
	a[1969 ].push_back(temp1);

	Node* temp2 = &nodePool[nodeCnt++];
	temp2->setName("TheManWhoSoldTheWorld");
	a[1970 ].push_back(temp2);

	Node* temp3 = &nodePool[nodeCnt++];
	temp3->setName("HunkyDory");
	a[1971 ].push_back(temp3);

	Node* temp4 = &nodePool[nodeCnt++];
	temp4->setName("TheRiseAndFallOfZiggyStardustAndTheSpidersFromMars");
	a[1972 ].push_back(temp4);

	Node* temp5 = &nodePool[nodeCnt++];
	temp5->setName("AladdinSane");
	a[1973 ].push_back(temp5);

	Node* temp6 = &nodePool[nodeCnt++];
	temp6->setName("PinUps");
	a[1973 ].push_back(temp6);

	Node* temp7 = &nodePool[nodeCnt++];
	temp7->setName("DiamondDogs");
	a[1974 ].push_back(temp7);

	Node* temp8 = &nodePool[nodeCnt++];
	temp8->setName("YoungAmericans");
	a[1975 ].push_back(temp8);

	Node* temp9 = &nodePool[nodeCnt++];
	temp9->setName("StationToStation");
	a[1976 ].push_back(temp9);

	Node* temp10 = &nodePool[nodeCnt++];
	temp10->setName("Low");
	a[1977 ].push_back(temp10);

	Node* temp11 = &nodePool[nodeCnt++];
	temp11->setName("Heroes");
	a[1977 ].push_back(temp11);

	Node* temp12 = &nodePool[nodeCnt++];
	temp12->setName("Lodger");
	a[1979 ].push_back(temp12);

	Node* temp13 = &nodePool[nodeCnt++];
	temp13->setName("ScaryMonstersAndSuperCreeps");
	a[1980 ].push_back(temp13);

	Node* temp14 = &nodePool[nodeCnt++];
	temp14->setName("LetsDance");
	a[1983 ].push_back(temp14);

	Node* temp15 = &nodePool[nodeCnt++];
	temp15->setName("Tonight");
	a[1984 ].push_back(temp15);

	Node* temp16 = &nodePool[nodeCnt++];
	temp16->setName("NeverLetMeDown");
	a[1987 ].push_back(temp16);

	Node* temp17 = &nodePool[nodeCnt++];
	temp17->setName("BlackTieWhiteNoise");
	a[1993 ].push_back(temp17);

	Node* temp18 = &nodePool[nodeCnt++];
	temp18->setName("1.Outside");
	a[1995 ].push_back(temp18);

	Node* temp19 = &nodePool[nodeCnt++];
	temp19->setName("Earthling");
	a[1997 ].push_back(temp19);

	Node* temp20 = &nodePool[nodeCnt++];
	temp20->setName("Hours");
	a[1999 ].push_back(temp20);

	Node* temp21 = &nodePool[nodeCnt++];
	temp21->setName("Heathen");
	a[2002 ].push_back(temp21);

	Node* temp22 = &nodePool[nodeCnt++];
	temp22->setName("Reality");
	a[2003 ].push_back(temp22);

	Node* temp23 = &nodePool[nodeCnt++];
	temp23->setName("TheNextDay");
	a[2013 ].push_back(temp23);

	Node* temp24 = &nodePool[nodeCnt++];
	temp24->setName("BlackStar");
	a[2016 ].push_back(temp24);

}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	init();

	int T, start, end; cin >> T;
	while (T--) {
		cin >> start >> end;
		int cnt = 0;
		for (int i = start; i <= end; ++i) cnt += a[i].len;
		cout << cnt << '\n';
		if (cnt == 0) continue;
		for (int i = start; i <= end; ++i) {
			a[i].print(i);
		}
	}
}