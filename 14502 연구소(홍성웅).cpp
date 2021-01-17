#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
struct Point {
	int y, x;
};
int arr[8][8];
int dy[] = { 1,-1,0,0 };
int dx[] = { 0,0,1,-1 };
bool visited[8][8];
int n, m,res;
void bfs() {
	queue<Point> q;
	int tmp[8][8];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			tmp[i][j] = arr[i][j];
			if (arr[i][j] == 2) {
				q.push({ i,j });
			}
		}
	}
	while (q.size()) {
		int y = q.front().y;
		int x = q.front().x;
		q.pop();
		for (int i= 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 0 && ny <= n - 1 && nx >= 0 && nx <= m - 1 && tmp[ny][nx] == 0) {
				tmp[ny][nx] = 2;
				q.push({ ny,nx });
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (tmp[i][j] == 0) {
				cnt++;
			}
		}
	}
	res = max(res, cnt);
}
void wall(int cnt) {
	if (cnt == 3) {
		bfs();
		return;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0) {
				arr[i][j] = 1;
				wall(cnt + 1);
				arr[i][j] = 0;
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0) {
				arr[i][j] = 1;
				wall(1);
				arr[i][j] = 0;
			}
		}
	}
	cout << res << '\n';
}