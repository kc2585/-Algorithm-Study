#include<iostream>

using namespace std;

int arr[20];
bool chk[20 * 100000 + 1];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i < (1 << n); i++) {
		int sum = 0;
		for (int j = 0; j < n; j++) {
			if ((i & (1 << j)) != 0) {
				sum += arr[j];
			}
		}
		chk[sum] = 1;
	}
	for (int i = 1; i < 20 * 100000 + 1; i++) {
		if (!chk[i]) {
			cout << i << '\n';
			break;
		}
	}
}