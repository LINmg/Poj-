#include<iostream>
#include<algorithm>

using namespace std;

bool cmp(pair<int, int>x, pair<int, int>y) {
	if (x.second < y.second) return true;
	else return false;
}

//这个用贪心，最后局部最优解的和似乎不是最优解？？
int xmain() {
	int result[10];
	int t, n, i, j;
	pair<int, int> buff[200];
	bool done[200];
	cin >> t;
	for (i = 0; i < t; i++) {
		cin >> n;
		int a, b;
		for (j = 0; j < n; j++) {
			cin >> a >> b;
			if (a > b) {
				int temp = a;
				a = b;
				b = temp;
			}
			buff[j] = pair<int, int>(a / 2 + a % 2, b / 2 + b % 2);
			done[j] = false;
		}
		sort(buff, buff + n, cmp);
		int c = 1, k = 0;
		while (c != 0) {
			int mao = 0;
			c = 0;
			for (mao = 0; mao < n; mao++) {
				if (!done[mao]) {
					done[mao] = true;
					c++;
					break;
				}
			}

			if (mao == n)break;
			for (j = mao + 1; j < n; j++) {
				if (buff[j].first > buff[mao].second && !done[j]) {
					done[j] = true;
					c++;
					mao = j;
				}
			}
			k++;
		}
		result[i] = k;
	}
	for (i = 0; i < t; i++) {
		cout << result[i] << endl;
	}
	return 0;
}