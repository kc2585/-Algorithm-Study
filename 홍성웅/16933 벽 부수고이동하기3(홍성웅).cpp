#include<iostream>
#include<queue>
#include<string>
using namespace std;
typedef struct {
	int y, x, w, cnt;
	bool night;
}node;
int n, m, k;
bool visited[1001][1001][11];
int arr[1001][1001];
int dy[] = { 1,-1,0,0 };
int dx[] = { 0,0,1,-1 };

void bfs() {
	queue<node> q;
	q.push({ 0,0,0,1,0 });
	visited[0][0][0] = 1;
	while (q.size()) {
		int y = q.front().y;
		int x = q.front().x;
		int w = q.front().w;
		int cnt = q.front().cnt;
		bool night = q.front().night;
		q.pop();
		if (y == n - 1 && x == m - 1) {
			cout << cnt << '\n';
			return;
		}
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 0 && ny < n && nx >= 0 && nx < m) {
				if (arr[ny][nx] == 1) {
					if ( w<k&& !visited[ny][nx][w + 1]) {
						if (!night) {
							q.push({ ny,nx,w + 1,cnt + 1,!night });
							visited[ny][nx][w + 1] = 1;
						}
						else {
							q.push({ y,x,w,cnt + 1 ,!night});
						}
					}
				}
				else {
					if (!visited[ny][nx][w]) {
						q.push({ ny,nx,w,cnt + 1,!night });
						visited[ny][nx][w] = 1;
					}
				}
				
			}
		}
	}
	cout << -1 << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			arr[i][j] = s[j] - '0';
		}
	}
	bfs();
}