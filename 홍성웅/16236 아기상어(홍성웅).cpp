#include<iostream>
#include<queue>
#include<string.h>
using namespace std;
int n;
int shark_y, shark_x, shark_size = 2;
int eat_cnt, res;
int arr[21][21];
int min_y = 21, min_x = 21, min_dist = 401;
int time[21][21];
int dy[] = { 1,-1,0,0 };
int dx[] = { 0,0,1,-1 };
void bfs(int y, int x) {
	queue<pair<int, int>>q;
	memset(time, -1, sizeof(time));
	min_y = 21; min_x = 21; min_dist = 401;
	q.push({ y,x });
	time[y][x] = 0;
	while (q.size()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (time[ny][nx] != -1 || arr[ny][nx] > shark_size)continue;
			if (ny >= 0 && nx >= 0 && ny < n && nx < n) {
				time[ny][nx] = time[y][x] + 1;
				if (arr[ny][nx] != 0 && shark_size > arr[ny][nx]) {
					if (min_dist > time[ny][nx]) {
						min_y = ny;
						min_x = nx;
						min_dist = time[ny][nx];
					}
					else if (min_dist == time[ny][nx]) {
						if (min_y == ny) {
							if (min_x > nx) {
								min_y = ny;
								min_x = nx;
							}
						}
						else if (min_y > ny) {
							min_x = nx;
							min_y = ny;
						}
					}
				}
				q.push({ ny,nx });
			}
		}
	}

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 9) {
				shark_y = i;
				shark_x = j;
				arr[i][j] = 0;
			}
		}
	}
	while (1) {
		bfs(shark_y, shark_x);
		if (min_y != 21 && min_x != 21) {
			res += time[min_y][min_x];

			eat_cnt++;
			if (eat_cnt == shark_size) {
				shark_size++;
				eat_cnt = 0;
			}

			arr[min_y][min_x] = 0;
			shark_x = min_x;
			shark_y = min_y;
		}
		else break;
	}
	cout << res << '\n';
}