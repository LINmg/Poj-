#include<stdio.h>
#include<algorithm>
#include <queue>
#include <xfunctional>
#define Max 20000
using namespace std;

/*
int l, n;
int wood[Max];

int main() {
	int i,j;
	long long ans;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf(" %d", &wood[i]);
	}
	ans = 0; i = 0;
	sort(wood, wood + n);
	while (i <n-1) {
		int t = wood[i] + wood[i + 1];
		wood[i + 1] = t;
		j = i + 1;
		while (j<n-1 &&wood[j]>wood[j+1]) {
			swap(wood[j], wood[j + 1]);
			j++;
		}
		ans += t;
		i++;
	}
	printf("%lld\n", ans);
}
*/

//另一种解法，利用优先队列
int l, n;


int main() {
	int i, j;
	long long ans;
	priority_queue <int, vector<int>,greater<int> > pque;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf(" %d", &j);
		pque.push(j);
	}
	ans = 0; i = 0;
	while (pque.size>1) {
		i = pque.top();
		pque.pop();
		j = pque.top();
		pque.pop();
		ans += i + j;
		pque.push(i + j);
	}

	printf("%d\n", ans);
	return 0;
}