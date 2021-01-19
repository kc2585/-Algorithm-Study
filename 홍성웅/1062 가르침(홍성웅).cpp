#include<iostream>
#include<string>

using namespace std;
int n, k;
int res;
int words[51];
int max(int a, int b) { return a > b ? a : b; }
int sol(int idx,int cnt) {
	int ans = 0;
	if (cnt == k) {
		for (int i = 0; i < n; i++) {
			if ((words[i] & res) == words[i]) {
				ans++;
			}
		}
		return ans;
	}

	for (int i = idx; i < 26; i++) {
		if ((res & (1 << i)) == 0) {
			res |= (1 << i);
			ans= max(ans,sol(i+1,cnt + 1));
			res &= ~(1 << i);
		}
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < s.length(); j++) {
			words[i]|=(1<<(s[j]-'a'));
		}
	}
	res |= (1 << ('a' - 'a'));
	res |= (1 << ('n' - 'a'));
	res |= (1 << ('t' - 'a'));
	res |= (1 << ('c' - 'a'));
	res |= (1 << ('i' - 'a'));

	if (k < 5 || k == 26)
		cout << (k == 26 ? n : 0) << endl;
	else {
		cout << sol(0, 5);
	}
}
