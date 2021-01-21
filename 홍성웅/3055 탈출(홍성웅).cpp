#include<iostream>
#include<queue>
using namespace std;
struct node {
	int y, x;
};
int r, c;
char arr[51][51];
int visited[51][51];
int dy[] = { 1,-1,0,0 };
int dx[] = { 0,0,1,-1 }; 
queue<node> river;
queue<node> q;
void bfs() {
	while (q.size()) {
		int size = river.size();
		for (int i = 0; i < size; i++) {
			int y = river.front().y;
			int x = river.front().x;
			river.pop();
			for (int j = 0; j < 4; j++) {
				int ny = y + dy[j];
				int nx = x + dx[j];
				if (ny >= 0 && nx >= 0 && ny < r && nx < c) {
					if (arr[ny][nx] == '.') {
						arr[ny][nx] = '*';
						river.push({ ny,nx });
					}
				}
			}
		}
		size = q.size();
		for (int i = 0; i < size; i++) {
			int y = q.front().y;
			int x = q.front().x;
			q.pop();
			if (arr[y][x] == 'D') {
				cout << visited[y][x]-1<<'\n';
				return;
			}
			for (int j = 0; j < 4; j++) {
				int ny = y + dy[j];
				int nx = x + dx[j];
				if (ny >= 0 && nx >= 0 && ny < r && nx < c) {
					if (!visited[ny][nx]&&arr[ny][nx] != 'X'&&arr[ny][nx]!='*') {
						visited[ny][nx] = visited[y][x]+1;
						q.push({ ny,nx });
					}
				}
			}
		}
	}
	cout << "KAKTUS\n";
}
int main() {
	ios::sync_with_stdio(0);
	cout.tie(0);cin.tie(0);

	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == '*') {
				river.push({ i,j });
			}
			else if (arr[i][j] == 'S') {
				q.push({ i, j });
				visited[i][j] = 1;
			}
		}
	}
	bfs();
}