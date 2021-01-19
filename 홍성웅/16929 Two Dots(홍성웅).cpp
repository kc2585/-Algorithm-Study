#include<iostream>
#include<string>
using namespace std;

int n, m;
int color[51][51];
int sum[51][51];
int dy[] = { 1,-1,0,0 };
int dx[] = { 0,0,1,-1 };
bool flag[51][51];
bool chk;
void dfs(int y, int x, int cnt) {
	if (chk) return;
	if (flag[y][x]) {
		if (cnt - sum[y][x] >= 4) chk = true;
		return;
	}
	flag[y][x] = 1;
	sum[y][x] = cnt;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny<0 || ny>n - 1 || nx<0 || nx>m - 1)continue;
		if (color[y][x] == color[ny][nx]) {
			dfs(ny, nx, cnt + 1);
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			color[i][j] = s[j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!flag[i][j]) {
				dfs(i, j, 0);
				if(chk){
					cout << "Yes\n";
					return 0;
				}
			}
		}
	}
	cout << "No\n";
}