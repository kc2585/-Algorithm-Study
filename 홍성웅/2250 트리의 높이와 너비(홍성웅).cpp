#include<iostream>
#include<algorithm>
using namespace std;
int n;
int arr[10001][2];
int visited[10001];
int high[10001];
int low[10001];
int cnt = 1;
void Inorder(int node, int level) {
	int l = arr[node][0];
	int r = arr[node][1];
	if (l>0) {
		Inorder(l, level + 1);
	}
	low[level] = min(cnt, low[level]);
	high[level] = max(cnt, high[level]);
	cnt++;
	if (r>0) {
		Inorder(r, level + 1);
	}
}
void sol() {
	int res = high[1]-low[1]+1;
	int depth = 1;
	for (int i = 2; i <= n; i++) {
		if (res < high[i] - low[i]+1) {
			res = high[i] - low[i]+1;
			depth = i;
		}
	}
	cout << depth << ' ' << res << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;

	for (int i = 0; i <= 10000; i++) {
		low[i] = 987654321;
	}
	for (int i = 0; i < n; i++) {
		int node, l, r;
		cin >> node >> l >> r;
		visited[node]++;
		if (l != -1) {
			visited[l]++;
		}
		arr[node][0] = l;
		if (r != -1) {
			visited[r]++;
		}
		arr[node][1] = r;
	}
	int root;
	for (int i = 1; i <= n; i++) {
		if (visited[i] == 1) {
			root = i;
		}
	}
	Inorder(root, 1);
	sol();
}