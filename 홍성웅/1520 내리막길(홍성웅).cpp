#include<iostream>
#include<string.h>
using namespace std;
int arr[501][501];
int visited[501][501];
int n, m;
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
int dfs(int y, int x) {
	if (y == n - 1 && x == m - 1) {
		return 1;
	}
	if (visited[y][x]!=-1) return visited[y][x];
	visited[y][x] = 0;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (arr[ny][nx] < arr[y][x] && ny >= 0 && ny < n && nx >= 0 && nx < m) {
			visited[y][x] += dfs(ny, nx);
		}
	}
	return visited[y][x];
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
	memset(visited, -1, sizeof(visited));
	cout << dfs(0, 0) << '\n';
}