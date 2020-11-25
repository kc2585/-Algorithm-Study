#include<iostream>
#include<queue>
#include<string.h>
using namespace std;
struct P{
	int y, x, cnt;
};
int arr[301][301];
bool visited[301][301];
int l;
int dy[] = { -2,-2,-1,-1,1,1,2,2 };
int dx[] = { -1,1,-2,2,-2,2,-1,1 };
queue<P> q;
void bfs(int Y,int X) {
	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		int cnt = q.front().cnt;
		q.pop();
		if (y == Y && x == X) {
			cout << cnt << '\n';
		}
		for (int i = 0; i < 8; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny<0 || ny>l - 1 || nx<0 || nx>l - 1) continue;
			if (!visited[ny][nx]) {
				visited[ny][nx] = 1;
				q.push({ ny,nx,cnt + 1 });
			}
		}
	}
	while (q.size()) q.pop();
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		memset(visited, 0, sizeof(visited));
		cin >> l;
		int a, b;
		cin >> a >> b;
		visited[a][b] = 1;
		q.push({ a,b,0 });
		cin >> a >> b;
		bfs(a, b);
	}
}