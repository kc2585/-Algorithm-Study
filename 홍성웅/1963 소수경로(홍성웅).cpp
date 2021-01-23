#include<iostream>
#include<queue>
#include<cstring>
#include<string>
#include<string.h>
using namespace std;
struct node {
	int num, cnt;
};
bool prime[10000];
bool visited[10000];
int n;
int start;
int goal;

void search_Prime() {
	prime[0] = 1;
	prime[1] = 1;
	for (int i = 2; i <= 10000; i++) {
		if (prime[i]) continue;
		for (int j = 2 * i; j <= 10000; j += i) {
			prime[j] = 1;
		}
	}
}
void bfs() {
	queue<node> q;
	memset(visited, 0, sizeof(visited));
	q.push({ start,0 });
	visited[start]=1;
	while (q.size()) {
		int num = q.front().num;
		int cnt = q.front().cnt;
		q.pop();
		if (num == goal) {
			cout << cnt << '\n';
			return;
		}
		for (int i = 0; i < 4; i++) {
			string s = to_string(num);
			for (int j = 0; j < 10; j++) {
				s[i] = j + '0';
				int tmp = stoi(s);
				if (tmp >= 1000 && !prime[tmp] && !visited[tmp]) {
					q.push({ tmp, cnt + 1 });
					visited[tmp] = 1;
				}
			}
		}
	}
	cout << "Impossible\n";
	return;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);


	search_Prime();
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> start >> goal;
		bfs();
	}
}