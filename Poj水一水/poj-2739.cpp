#include<iostream>
#include<algorithm>

using namespace std;

bool prime[10001];
int prime1[2000];
int result[10001];

void isprime() {
	int p = 0;
	for (int i = 0; i < 10001; i++) {
		prime[i] = true;
		result[i] = 0;
	}
	prime[0] = prime[1] = false;
	for (int i = 2; i < 10001; i++) {
		if (prime[i] == true) {
			prime1[p++] = i;
			for (int j = i+i; j < 10001; j += i) {
				prime[j] = false;
			}
		}
	}
}
void solve() {
	for (int i = 0; i<1229; i++) {
		int a = 0;
		for (int j= i; j<1229; j++){
			a += prime1[j];
			if (a > 10000) continue;
			result[a]++;
		}
	}
}
int main() {
	isprime();
	solve();
	int a;
	while (cin >> a&&a != 0) {
		cout << result[a] << endl;
	}
	return 0;
}