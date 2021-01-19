#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
int n;
int oper[4];
vector<int> v;
ll MAX = -1e9;
ll MIN = 1e9;
void sol(int plus, int minus, int multiply, int divide, int len, ll sum,int idx) {
	if (len == n - 1) {
		MAX = max(MAX, sum);
		MIN = min(MIN, sum);
		return;
	}
	if (plus > 0) sol(plus - 1, minus, multiply, divide, len + 1, sum + v[idx],idx+1);
	if (minus > 0) sol(plus, minus-1, multiply, divide, len + 1, sum - v[idx], idx + 1);
	if (multiply > 0) sol(plus , minus, multiply-1, divide, len + 1, sum * v[idx], idx + 1);
	if (divide > 0) sol(plus, minus, multiply, divide-1, len + 1, sum / v[idx], idx + 1);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	cin >> n;
	for(int i=0;i<n;i++){
		int num; cin >> num;
		v.push_back(num);
	}
	for (int i = 0; i <4; i++) {
		cin >> oper[i];
	}
	sol(oper[0], oper[1], oper[2], oper[3], 0, v[0], 1);
	cout << MAX << '\n' << MIN << '\n';
}