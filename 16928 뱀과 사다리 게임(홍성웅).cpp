#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int n, m;
int maze[101];
bool visited[101];
int ans=1e9;
queue<pair<int,int>> q;
void bfs() {
	while (q.size()) {
		int idx = q.front().first;
		int cnt = q.front().second;
		if (maze[idx] != 0) {
			idx = maze[idx];
		}
		q.pop();
		if (idx == 100) {
			ans = min(ans, cnt);
			continue;
		}
		for (int i = 0; i < 6; i++) {
			int nx = idx + i + 1;
			if (1 <= nx && nx <= 100 && !visited[nx]) {
				visited[nx] = true;
				q.push({ nx,cnt + 1 });
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for (int i = 0; i < n+m; i++) {
		int a, b;
		cin >> a >> b;
		maze[a] = b;
	}
	q.push({ 1,0 });
	visited[1] = 1;
	bfs();
	cout << ans << '\n';
}