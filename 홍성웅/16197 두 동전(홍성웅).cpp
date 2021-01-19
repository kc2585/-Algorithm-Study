#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n, m;
int res = 1e9;
char MAP[21][21];
int dy[] = { 1,-1,0,0 };
int dx[] = { 0,0,1,-1 };
vector<pair<int, int>>v;
bool chk(int Y, int X) {
	if (Y<0 || Y>n - 1 || X<0 || X>m - 1) return false;
	return true;
}
void go(int y, int x, int yy, int xx,int cnt, int dir) {
	if (cnt > res) return;
	if (cnt > 10) {
		res = min(res, cnt);
		return;
	}
	int ny = y + dy[dir];
	int nx = x + dx[dir];
	int nyy = yy + dy[dir];
	int nxx = xx + dx[dir];
	if (chk(ny, nx) == false && chk(nyy, nxx) == false) return;
	if (chk(ny, nx) == true && chk(nyy, nxx) == false) {
		res = min(res, cnt);
		return;
	}
	if (chk(ny, nx) == false && chk(nyy, nxx) == true) {
		res = min(res, cnt);
		return;
	}
	if (MAP[ny][nx] == '#') {
		ny = y;
		nx = x;
	}
	if (MAP[nyy][nxx] == '#') {
		nyy = yy;
		nxx = xx;
	}
	for (int i = 0; i < 4; i++) {
		go(ny, nx, nyy, nxx, cnt + 1, i);
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] == 'o') v.push_back({ i,j });
		}
	}
	for (int i = 0; i < 4; i++) {
		go(v[0].first, v[0].second, v[1].first, v[1].second, 1, i);
	}
	if (res > 10) cout << -1 << '\n';
	else cout << res << '\n';
}