#include<iostream>
#include<queue>
#include<string.h>
using namespace std;
struct P {
	int y, x, cnt;
};
int m, n,res;
int arr[1001][1001];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
queue<P> q;
void bfs() {
	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		int cnt = q.front().cnt;
		res = max(res, cnt);
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny<0 || ny>n - 1 || nx<0 || nx>m - 1) continue;
			if (arr[ny][nx] == 0) {
				arr[ny][nx] = 1;
				q.push({ ny, nx, cnt+1 });
			}
		}
	}
	bool chk = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0) chk = 1;
		}
	}
	if (chk) cout << -1 << '\n';
	else cout << res << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> m >> n;
	memset(arr, -1, sizeof(arr));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j]==1) q.push({ i,j,0 });
		}
	}
	bfs();
}