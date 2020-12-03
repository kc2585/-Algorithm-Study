#include<iostream>
#include<vector>
#include<string>
using namespace std;
int k;
bool num[10];
vector<char> symbol;
vector<string> res;
string s;
void sol(int cnt) {
	
	if (cnt == k+1) {
		bool chk = false;
		for (int i = 1; i < s.length(); i++) {
			char oper = symbol[i - 1];
			switch (oper){
			case '<': {
				if (s[i - 1] > s[i]) chk = true;
				break;
			}
			case '>': {
				if (s[i - 1] < s[i]) chk = true;
				break;
			}
			}
			if (chk) {
				return;
			}
		}
		res.push_back(s);
		return;
	}
	for (int i = 0; i < 10; i++) {
		if (!num[i]) {
			num[i] = 1;
			s.push_back(i+'0');
			sol(cnt + 1);
			s.pop_back();
			num[i] = 0;
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);

	cin >> k;
	for (int i = 0; i < k; i++) {
		char a;
		cin >> a; symbol.push_back(a);
	}
	sol(0);
	cout << res.back() << '\n' << res.front();
}