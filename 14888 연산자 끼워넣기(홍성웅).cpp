#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll MAX = -100000000;
ll MIN = 100000000;
int n;
vector<int> num;
vector<int> oper;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	num.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	for (int i = 0; i < 4; i++) {
		int cnt; cin >> cnt;
		for (int j = 0; j < cnt; j++) {
			oper.push_back(i);
		}
	}
	do {
		ll sum = num[0];
		for (int i = 0; i < oper.size(); i++) {
			if (oper[i] == 0) sum += num[i + 1];
			if (oper[i] == 1) sum -= num[i + 1];
			if (oper[i] == 2) sum *= num[i + 1];
			if (oper[i] == 3) sum /= num[i + 1];
		}
		MAX = max(sum, MAX);
		MIN = min(sum, MIN);
	} while (next_permutation(oper.begin(), oper.end()));
	cout << MAX << '\n' <<  MIN << '\n';
}