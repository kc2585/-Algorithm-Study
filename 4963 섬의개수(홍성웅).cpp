#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

int arr[51][51];
bool visited[51][51];
int dy[] = { -1,-1,-1,0,0,1,1,1 };
int dx[] = { -1,0,1,-1,1,-1,0,1 };
int cnt;
void dfs(int y, int x) {
	visited[y][x]=1;
	for (int i = 0; i < 8; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (!visited[ny][nx] && arr[ny][nx]) {
			dfs(ny, nx);
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);

	while (1) {
		int x, y;
		cin >> x >> y;
		if (x == 0 && y == 0) break;
		memset(arr, 0, sizeof(arr));
		memset(visited, 0, sizeof(visited));
		cnt = 0;
		for (int i = 0; i < y; i++) {
			for (int j = 0; j < x; j++) {
				cin >> arr[i][j];
			}
		}
		for (int i = 0; i < y; i++) {
			for (int j = 0; j < x; j++) {
				if (!visited [i][j] && arr[i][j]) {
					cnt++;
					dfs(i, j);
				}
			}
		}
		cout << cnt << '\n';
	}
}