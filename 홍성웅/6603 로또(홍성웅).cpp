#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
int n;
vector<int>v;
int arr[50];
bool chk[50];
void rec(int num,int cnt) {
	if (cnt == 6) {
		for (auto a : v) {
			cout << a << ' ';
		}
		cout << '\n';
	}
	for (int i = num; i < n; i++) {
		if (!chk[i]) {
			chk[i] = 1;
			v.push_back(arr[i]);
			rec(i,cnt + 1);
			chk[i] = 0;
			v.pop_back();
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	while (1) {
		cin >> n;
		if (n == 0) return 0;
		v.clear();
		memset(arr, 0, sizeof(arr));
		memset(chk, 0, sizeof(chk));
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		rec(0,0);
		cout << '\n';
	}
}
