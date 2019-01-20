#include <iostream>
using namespace std;
bool chick[14];
struct pos {
	int x;
	int y;
};
void init()
{
	for (int i = 0; i < 14; i++)
		chick[i] = false;
}
int distance(int x1, int y1, int x2, int y2)
{
	int temp = 0;
	if (x1 > x2)
		temp += x1 - x2;
	else
		temp += x2 - x1;
	if (y1 > y2)
		temp += y1 - y2;
	else
		temp += y2 - y1;
	return temp;
}
int main()
{
	pos chicken[14];
	pos home[100];
	long long totaldistance = 987654321;
	int housedistance[101] = { 0, };
	int n, m;
	int ans = 2000000000;
	cin >> n >> m;
	int chickenhouse = 0;
	int house = 0;
	int a[51][51] = { 0, };
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == 2)
			{
				chicken[chickenhouse].x = i;
				chicken[chickenhouse].y = j;
				chickenhouse++;
			}
			else if (a[i][j] == 1)
			{
				home[house].x = i;
				home[house].y = j;
				house++;
			}
		}
	for (int i = 0; i < (1 << chickenhouse); i++) {
		int cnt = 0;
		int len = 0;
		totaldistance = 0;
		init();
		for (int j = 0; j < chickenhouse; j++)
		{
			if (i&(1 << j))
			{
				cnt++;
				chick[j] = true;
			}
		}
		if (cnt <= m)
		{
			for (int i = 0; i < house; i++)
			{
				housedistance[i] = 987654321;
				for (int j = 0; j < chickenhouse; j++)
				{
					if (chick[j])
					{
						int templen = distance(home[i].x, home[i].y, chicken[j].x, chicken[j].y);
						if (housedistance[i] > templen)
							housedistance[i] = templen;
					}
				}
			}
		}
		for (int i = 0; i < house; i++)
			totaldistance += housedistance[i];

		if (totaldistance != 0 && totaldistance < ans)
			ans = totaldistance;
	}
	cout << ans << '\n';

}