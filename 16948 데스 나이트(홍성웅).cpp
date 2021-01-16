#include<iostream>
#include<queue>

using namespace std;
struct P {
	int y, x, cnt;
};
int arr[201][201];
int ans = -1;
int dy[] = { -2,-2,0,0, 2,2 };
int dx[] = { -1,1,-2,2,-1,1 };
bool visited[201][201];
queue<P> q;
int n, a, b, r, c;

void bfs() {
	q.push({ a,b,0 });
	visited[a][b] = 1;
	while (q.size()) {
		int y = q.front().y;
		int x = q.front().x;
		int cnt = q.front().cnt;
		q.pop();
		if (y == r && x == c) {
			ans = cnt;
			return;
		}
		for (int i = 0; i < 6; i++) {
			int ny = y + dy[i]; int nx = x + dx[i];
			if (ny >= 0 && ny <= n - 1 && nx >= 0 && nx <= n - 1 && !visited[ny][nx]) {
				visited[ny][nx] = 1;
				q.push({ ny,nx,cnt + 1 });
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> a >> b >> r >> c;
	bfs();
	cout << ans << '\n';
}