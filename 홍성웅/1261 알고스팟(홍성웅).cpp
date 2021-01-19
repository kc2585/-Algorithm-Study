#include<iostream>
#include<queue>
using namespace std;

int arr[101][101];
bool visited[101][101];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
int n, m;

void bfs() {
	visited[0][0] = 1;
	pq.push({ 0,{0,0} });
	while (pq.size()) {
		int y= pq.top().second.first;
		int x = pq.top().second.second;
		int block = pq.top().first;
		pq.pop();
		if (x == m - 1 && y == n - 1) {
			cout << block << '\n';
			return;
		}
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny<0 || ny>n - 1 || nx<0 || nx>m - 1) continue;
			if (!visited[ny][nx]) {
				if (arr[ny][nx] == 1) pq.push({ block + 1,{ny,nx} });
				else pq.push({ block,{ny,nx }});
				visited[ny][nx] = 1;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			arr[i][j] = s[j] - '0';
		}
	}
	bfs();
}