#include<iostream>
#include<queue>

using namespace std;
int n, k;
int mini = 1e9;
int visit[101010];
bool check[101010];
struct Point {
	int cur;
	int d;
};
void bfs()
{
	queue<Point> q;
	vector<int> v;
	q.push({ n,0 });
	check[n] = true;
	while (q.size())
	{
		int x = q.front().cur;
		int d = q.front().d;
		q.pop();
		if (x == k)
		{
			cout << d << '\n';
			int idx = x;
			while (idx != n)
			{
				v.push_back(idx);
				idx = visit[idx];
			}
			v.push_back(n);
			for (int i = v.size() - 1; i >= 0; i--)
				cout << v[i] << ' ';
			cout << '\n';
			return;
		}
		int next[] = { x - 1,x + 1,2 * x };
		for (int i = 0; i < 3; i++)
		{
			if (next[i] >= 0 && next[i] <= 100000 && !check[next[i]])
			{
				q.push({ next[i],d + 1 });
				visit[next[i]] = x;
				check[next[i]] = true;
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	bfs();

}