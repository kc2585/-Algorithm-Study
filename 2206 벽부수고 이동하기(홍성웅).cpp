#include<iostream>
#include<queue>
#include<algorithm>
#include<string.h>
using namespace std;
struct Point {
	int y, x, w,cnt;
};
int arr[1001][1001];
bool visited[1001][1001][2];
int n, m;
int ans = 0;
int dy[] = { 1,-1,0,0 };
int dx[] = { 0,0,1,-1 };
void bfs() {
	queue<Point> q;
	q.push({ 0,0,0,1 });
	visited[0][0][0] = 1;
	while (q.size()) {
		int y = q.front().y;
		int x = q.front().x;
		int w = q.front().w;
		int cnt = q.front().cnt;
		q.pop();
		if (y == n - 1 && x == m - 1) {
			ans = cnt;
			return;
		}
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 0 && ny < n && nx >= 0 && nx < m) {
				if (arr[ny][nx] == 1 && w == 0) {
					q.push({ ny,nx,w + 1,cnt + 1 });
					visited[ny][nx][w + 1] = 1;
				}
				else if (arr[ny][nx] == 0 && !visited[ny][nx][w]) {
					q.push({ ny,nx,w,cnt + 1 });
					visited[ny][nx][w] = 1;
				}
			}
		}
	}
	ans = -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			arr[i][j] = s[j] - '0';
		}
	}
	bfs();
	cout << ans << '\n';
}