#include<iostream>
#include<algorithm>
using namespace std;
int n, m;
int res = -1;
int arr[501][501];
bool visited[501][501];
int dy[] = { 1,-1,0,0 };
int dx[] = { 0,0,1,-1 };
int ex[4][4] = { {0, 0, 0, 1}, {0, 1, 2, 1}, {0, 0, 0, -1}, {0, -1, 0, 1} };
int ey[4][4] = { {0, 1, 2, 1}, {0, 0, 0, 1}, {0, 1, 2, 1}, {0, 1, 1, 1} };

void dfs(int y, int x, int sum, int cnt) {
	if (cnt == 4) {
		res = max(res, sum);
		return;
	}
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny<0 || ny>n-1 || nx < 0 || nx>m-1) continue;
		if (!visited[ny][nx]) {
			visited[ny][nx] = 1;
			dfs(ny, nx, sum + arr[ny][nx], cnt + 1);
			visited[ny][nx] = 0;
		}
	}
}
void ex_dfs(int y, int x) {
	for (int i = 0; i < 4; i++) {
		bool chk = 0;
		int sum = 0;
		for (int j = 0; j < 4; j++) {
			int ny = y + ey[i][j];
			int nx = x + ex[i][j];
			if (ny<0 || ny>n - 1 || nx<0 || nx>m - 1) {
				chk = 1;
				break;
			}
			sum += arr[ny][nx];
		}
		if (!chk) {
			res = max(res, sum);
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = 1;
			dfs(i, j, arr[i][j], 1);
			visited[i][j] = 0;
			ex_dfs(i, j);
		}
	}
	cout << res << '\n';
}