#include<iostream>

using namespace std;
int col[15];
int n, res;
bool chk(int y) {
	for (int i = 0; i < y; i++) {
		if (col[i] == col[y] || abs(col[i] - col[y]) == abs(i - y)) {
			return false;
		}
	}
	return true;
}
void N_Queen(int y) {
	if (y == n) res++;
	else {
		for (int i = 0; i < n; i++) {
			col[y] = i;
			if (chk(y)) {
				N_Queen(y + 1);
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	N_Queen(0);
	cout << res << '\n';
}