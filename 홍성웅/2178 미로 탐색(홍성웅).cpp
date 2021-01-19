#include<iostream>
#include<string.h>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;

int arr[101][101];
bool visited[101][101];
int dy[] = { 1,-1,0,0 };
int dx[] = { 0,0,1,-1 };
int n, m;
struct P
{
	int y, x, cnt;
};
void bfs() {
	visited[0][0] = 1;

	queue<P> q;
	q.push({ 0,0,1 });
	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		int cnt = q.front().cnt;
		q.pop();
		if (y == n - 1 && x == m - 1) {
			cout << cnt << '\n';
			return;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i]; int ny = y + dy[i];
			if (ny<0 || ny>n - 1 || nx<0 || nx>m - 1) continue;
			if (!visited[ny][nx] && arr[ny][nx]) {
				visited[ny][nx] = 1;
				q.push({ ny,nx,cnt + 1 });
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			arr[i][j] = s[j] - '0';
		}
	}
	bfs();
}