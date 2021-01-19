#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<string.h>
#include<set>
using namespace std;
int n, m;
vector<int> v;
int arr[1001][1001];
int Area[1001][1001];
bool visited[1001][1001];
int dy[] = { 1,-1,0,0 };
int dx[] = { 0,0,1,-1 };
void search_zero(int y,int x, int idx) {
	queue<pair<int,int>>q;
	int cnt = 0;
	q.push({ y,x });
	Area[y][x] = idx;
	while (q.size()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		cnt++;
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 0 && ny < n && nx >= 0 && nx < m) {
				if (arr[ny][nx] == 0 && !Area[ny][nx]) {
					Area[ny][nx] = idx;
					q.push({ ny,nx });
				}
			}
		}
	}
	v.push_back(cnt);
}
void countBlock(int y, int x) {
	if (!arr[y][x]) cout << 0;
	else {
		int cnt = 1;
		set<int> s;
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 0 && ny < n && nx >= 0 && nx < m) {
				s.insert(Area[ny][nx]);
			}
		}
		for (auto a : s) {
			cnt += v[a];
			cnt %= 10;
		}
		cout << cnt;
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
			arr[i][j] = s[j] - '0';
		}
	}
	v.push_back(0);
	int zero_area = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0 && !Area[i][j]) {
				search_zero(i, j, zero_area);
				zero_area++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			countBlock(i, j);
		}
		cout << '\n';
	}
}