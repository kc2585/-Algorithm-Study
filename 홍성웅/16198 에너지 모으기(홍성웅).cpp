#include<iostream>
#include<algorithm>
using namespace std;
int arr[10];
bool visited[10];
int n;

int back_tracking() {
	int res = 0;
	for (int i = 1; i < n - 1; i++) {
		if (visited[i]) continue;
		int left = i - 1;
		int right = i + 1;
		while (visited[left]) left--;
		while (visited[right]) right++;
		visited[i] = 1;
		res = max(res, back_tracking() + arr[left] * arr[right]);
		visited[i] = 0;
	}
	return res;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << back_tracking() << '\n';
}