#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct node {
	int y, x, d,cnt;
};
int w, h;
char arr[101][101];
int visited[101][101];
int dy[] = { 1,-1,0,0 };
int dx[] = { 0,0,1,-1 };
vector<pair<int, int>>v;
void bfs() {
	queue<node> q;
	q.push({ v[0].first,v[0].second,0,0 });
	q.push({ v[0].first,v[0].second,1 ,0});
	q.push({ v[0].first,v[0].second,2, 0 });
	q.push({ v[0].first,v[0].second,3 ,0});
	visited[v[0].first][v[0].second] = 0;
	while (q.size()) {
		int y = q.front().y;
		int x = q.front().x;
		int d = q.front().d;
		int cnt = q.front().cnt;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			int ncnt = cnt;
			if (ny < 0 || ny >= h || nx < 0 || nx >= w)continue;
			if (arr[ny][nx] == '*') continue;
			if (d != i) ncnt = ncnt + 1;
			if (visited[ny][nx] >= ncnt) {
				q.push({ ny,nx,i,ncnt });
				visited[ny][nx] = ncnt;
			}
		}
	}
	cout << visited[v[1].first][v[1].second]<<'\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> w >> h;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'C') {
				v.push_back({ i,j });
			}
			visited[i][j] = 987654321;
		}
	}
	bfs();
}