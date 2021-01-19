#include<iostream>

using namespace std;
int sdocu[9][9];
bool row[9][10];
bool col[9][10];
bool square[9][10];

void dfs(int cnt) {
	if (cnt == 81) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << sdocu[i][j] << ' ';
			}
			cout << '\n';
		}
		exit(0);
	}
	int x = cnt % 9;
	int y = cnt / 9;
	if (sdocu[y][x] == 0) {
		for (int k = 1; k <= 9; k++) {
			if (row[y][k] == false && col[x][k] == false && square[x / 3 + (y / 3) * 3][k] == false) {
				row[y][k] = true;
				col[x][k] = true;
				square[x / 3 + (y / 3) * 3][k] = true;
				sdocu[y][x] = k;
				dfs(cnt + 1);
				row[y][k] = false;
				col[x][k] = false;
				square[x / 3 + (y / 3) * 3][k] = false;
				sdocu[y][x] = 0;
			}
		}
	}
	else {
		dfs(cnt + 1);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> sdocu[i][j];
			if (sdocu[i][j] != 0) {
				row[i][sdocu[i][j]] = true;
				col[j][sdocu[i][j]] = true;
				square[j / 3 + (i / 3) * 3][sdocu[i][j]] = true;
			}
		}
	}
	dfs(0);
}