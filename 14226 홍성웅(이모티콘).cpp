#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

struct p{
	int len,clip, cnt;
};
bool visited[2001][2001];
int n;

void bfs() {
	queue<p> q;
	q.push({ 1,0,0 });
	visited[1][0] = 1;
	while (q.size()) {
		int len = q.front().len;
		int clip = q.front().clip;
		int cnt = q.front().cnt;
		q.pop();
		if (n == len) {
			cout << cnt<<'\n';
			return;
		}
		int nx[] = { len,len + clip,len - 1 };
		int ny[] = { len,clip,clip };
		for (int i = 0; i < 3; i++) {
			if (nx[i] < 0 | nx[i]>2 * n)continue;
			if (visited[nx[i]][ny[i]])continue;
			q.push({ nx[i],ny[i],cnt + 1 });
			visited[nx[i]][ny[i]] = 1;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	bfs();
}