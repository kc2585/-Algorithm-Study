#include<iostream>
#include<queue>
#include<string.h>
using namespace std;

int n, cnt, ex_cnt;
char arr[101][101];
char ex_arr[101][101];
bool visited[101][101];
bool ex_visited[101][101];
int dy[] = { 1,-1,0,0 };
int dx[] = { 0,0,1,-1 };
void bfs(int a, int b, char val) {
	queue<pair<int, int>>q;
	q.push({ a,b });
	visited[a][b] = 1;
	while (q.size()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 0 && ny < n && nx >= 0 && nx < n) {
				if (!visited[ny][nx]&&arr[ny][nx]==val) {
					q.push({ ny,nx });
					visited[ny][nx] = 1;
				}
			}
		}
	}
	cnt++;
}
void ex_bfs(int a, int b, char val) {
	queue<pair<int, int>>q;
	q.push({ a,b });
	ex_visited[a][b] = 1;
	while (q.size()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 0 && ny < n && nx >= 0 && nx < n) {
				if (!ex_visited[ny][nx] && ex_arr[ny][nx] == val) {
					q.push({ ny,nx });
					ex_visited[ny][nx] = 1;
				}
			}
		}
	}
	ex_cnt++;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'G') ex_arr[i][j] = 'R';
			else ex_arr[i][j] = arr[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) bfs(i, j, arr[i][j]);
			if (!ex_visited[i][j]) ex_bfs(i, j, ex_arr[i][j]);
		}
	}
	cout << cnt << ' ' << ex_cnt << '\n';
}