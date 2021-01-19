#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int n;
int sum[26];
vector<string> v;
void sol() {

	for (int i = 0; i <v.size() ; i++) {
		int pow = 1;
		for (int j = v[i].size() - 1; j >= 0; j--) {
			int idx = v[i][j] - 'A';
			sum[idx] += pow;
			pow *= 10;
		}
	}
	int num = 9;
	int res = 0;
	sort(sum, sum + 26);
	for (int i = 25; i >= 0; i--) {
		if (sum[i] == 0) break;
		res += sum[i] * num;
		num--;
	}
	cout << res << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i ++ ) {
		string s;
		cin >> s;
		v.push_back(s);
	}
	sol();
}