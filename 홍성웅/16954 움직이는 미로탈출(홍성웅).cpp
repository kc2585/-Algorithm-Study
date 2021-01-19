#include<iostream>
#include<string>
#include<queue>

using namespace std;
typedef struct {
	int t,y,x;
}node;
char arr[8][8];
char sharp[8][8][8];
vector<pair<int, int>>v;
int dy[]{ -1,-1,-1,0,0,0,1,1,1 };
int dx[]{ -1,0,1,-1,0,1,-1,0,1 };

bool chk(int y,int t) {
	for (int i = y - 1; i >= 0; i--) {
		for (int j = 0; j < 8; j++) {
			if (sharp[t][i][j] == '#') return false;
		}
	}
	return true;
}
void bfs() {
	queue<node> q;
	q.push({ 0,7,0 });
	while (q.size()) {
		int y = q.front().y;
		int x = q.front().x;
		int t = q.front().t;
		q.pop();
		if (y == 0) {
			cout << 1 << '\n';
			return;
		}
		if (chk(y, t)) {
			cout << 1 << '\n'; return;
		}
		for (int i = 0; i < 9; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			int nt = t + 1;
			if (ny >= 0 && ny < 8 && nx >= 0 && nx < 8) {
				if (sharp[t][ny][nx] == '.' && sharp[nt][ny][nx] == '.') {
					q.push({ nt,ny,nx });
				}
			}
		}
	}
	cout << 0 << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	for (int i = 0; i < 8; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < 8; j++) {
			arr[i][j]=s[j];
			if (arr[i][j] == '#') {
				sharp[0][i][j] = '#';
				v.push_back({ i,j });
			}
		}
	}
	for (int t = 0; t < 8; t++) {
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (sharp[t][i][j] == '#') continue;
				sharp[t][i][j] = '.';
			}
		}
	}
	for (int i = 0; i < v.size(); i++) {
		int y = v[i].first;
		int x = v[i].second;
		int t = 1;
		while (1) {
			int ny = y + 1;
			int nx = x;
			if (ny > 7)break;

			sharp[t][ny][nx] = '#';
			t++;
			y = ny;
			x = nx;
		}
	}
	bfs();
}