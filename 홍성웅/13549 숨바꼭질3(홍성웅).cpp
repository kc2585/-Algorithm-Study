#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
struct p{
	int idx, cnt;
};
int n, k;
int res = 100001;
bool chk[101010];

void bfs() {
	queue<p> q;
	q.push({ n,0 });
	chk[n] = 1;
	while (q.size()) {
		int idx = q.front().idx;
		int cnt = q.front().cnt;
		q.pop();
		if (idx == k) {
			res = min(res, cnt);
			continue;
		}
		int nx[] = { 2 * idx , idx - 1,idx + 1};
		for (int i = 0; i < 3; i++) {
			if (nx[i] >= 0 && nx[i] <= 100000 && !chk[nx[i]]) {
				if (i == 0) {
					q.push({ nx[i],cnt });
				}
				else q.push({ nx[i],cnt + 1 });
				chk[nx[i]] = 1;
			}
		}
	}
	cout << res << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;
	bfs();
}