#include<iostream>
#include<queue>
using namespace std;
int n, k;
bool visited[101010];
struct p{
	int idx, cnt;
};
void bfs(){
	queue<p> q;
	q.push({ n,0 });
	visited[n] = 1;
	while (q.size()) {
		int idx = q.front().idx;
		int cnt = q.front().cnt;
		q.pop();
		if (idx == k) {
			cout << cnt << '\n';
			return;
		}
		int nx[3] = { idx - 1,idx + 1,2 * idx };
		for (int i = 0; i < 3; i++) {
			if (nx[i] >= 0 && nx[i] <= 100000 && !visited[nx[i]]) {
				q.push({ nx[i],cnt + 1 });
				visited[nx[i]] = 1;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	bfs();
}