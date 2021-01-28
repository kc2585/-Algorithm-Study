#include<iostream>
#include<algorithm>
using namespace std;
int n;
int ans = 40001;
char arr[21][21];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	for (int k = 0; k < (1 << n); k++) {
		int sum = 0;
		for (int col = 0; col < n; col++) {
			int T_cnt = 0;
			for (int row = 0; row < n; row++) {
				char node = arr[row][col];
				if (k & (1 << row)) {
					if (node == 'T') {
						node = 'H';
					}
					else node = 'T';
				}
				if (node == 'T') T_cnt++;
			}
			sum += min(T_cnt, n - T_cnt);
		}
		ans = min(ans, sum);
	}
	cout << ans << '\n';
}