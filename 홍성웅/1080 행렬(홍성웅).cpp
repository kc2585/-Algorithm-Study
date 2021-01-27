#include<iostream>
#include<string>
using namespace std;

int n, m;
int arr[51][51];
int res[51][51];

void XOR(int y, int x) {
	for (int i = y; i < y + 3; i++) {
		for (int j = x; j<x + 3; j++) {
			arr[i][j] = 1 - arr[i][j];
		}
	}
}
bool equal() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] != res[i][j]) {
				return false;
			}
		}
	}
	return true;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			arr[i][j] = s[j] - '0';
		}
	}
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			res[i][j] = s[j] - '0';
		}
	}
	bool chk = false;
	int cnt = 0;
	if (n >= 3 && m >= 3) {
		for (int i = 0; i <= n-3; i++) {
			for (int j = 0; j <= m - 3; j++) {
				if (arr[i][j] != res[i][j]) {
					XOR(i, j);
					cnt++;
				}
				if (equal()) {
					chk = 1; break;
				}
			}
			if (chk) break;
		}
	}
	if (n < 3 || m < 3) {
		if(equal()) chk=true;
	}
	if (chk) {
		cout << cnt << '\n';
	}
	else cout << -1 << '\n';
}