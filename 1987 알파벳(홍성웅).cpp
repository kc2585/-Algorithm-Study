#include<iostream>
#include<string>
using namespace std;
int Y, X;
int dy[] = { 1,-1,0,0 };
int dx[] = { 0,0,1,-1 };
int arr[21][21];
bool visited[26];
int ans = 0;
void dfs(int y, int x, int cnt) {
	if (ans < cnt) ans = cnt;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny >= 0 && ny < Y && nx >= 0 && nx < X && !visited[arr[ny][nx]]) {
			visited[arr[ny][nx]] = 1;
			dfs(ny, nx, cnt + 1);
			visited[arr[ny][nx]] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> Y >> X;
	string s;
	for (int i = 0; i < Y; i++) {
		cin >> s;
		for (int j = 0; j < X; j++) {
			arr[i][j] = s[j] - 'A';
		}
	}
	visited[arr[0][0]] = 1;
	dfs(0, 0, 1);
	cout << ans << '\n';
}