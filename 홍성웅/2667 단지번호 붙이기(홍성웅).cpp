#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int arr[26][26];
int n;
bool visited[26][26];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int num[1000];
int cnt = 0;
void dfs(int y,int x) {
	visited[y][x] = 1;
	num[cnt]++;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny<0 || ny>n - 1 || nx<0 || nx>n - 1||arr[ny][nx]==0) continue;
		if (visited[ny][nx]) continue;
		dfs(ny, nx);
	}
}
int main() {
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) {
			arr[i][j] = s[j] - '0';
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j] && arr[i][j]) {
				dfs(i, j);
				cnt++;
			}
		}
	}
	cout << cnt << '\n';
	sort(num, num + cnt);
	for (int i = 0; i < cnt;i++) {
		cout << num[i] << '\n';
	}
}