#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int n;
int arr[100001];
int ex_arr[100001];
int res[100001];
bool chk(int a[]) {
	for (int i = 0; i < n; i++) {
		if (a[i] != res[i]) return false;
	}
	return true;
}
void go(int a[], int idx) {
	for (int i = -1; i < 2; i++) {
		if (idx + i >= 0 && idx + i < n) {
			a[idx + i] = 1 - a[idx + i];
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;

	string s;
	cin >> s;
	for (int i = 0; i < n; i++) {
		arr[i] = s[i] - '0';
		ex_arr[i] = arr[i];
	}
	cin >> s;
	for (int i = 0; i < n; i++) {
		res[i] = s[i] - '0';
	}

	go(ex_arr, 0);
	int cnt = 0;
	int ex_cnt = 1;
	for (int i = 0; i < n-1; i++) {
		if (arr[i] != res[i]) {
			go(arr, i+1);
			cnt++;
		}
		if (ex_arr[i] != res[i]) {
			go(ex_arr, i+1);
			ex_cnt++;
		}
	}
	int ans = -1;
	if (chk(arr)) ans = cnt;
	else if (chk(ex_arr)) ans = ex_cnt;
	if (chk(arr) && chk(ex_arr)) ans = cnt < ex_cnt ? cnt : ex_cnt;
	cout << ans << '\n';
}