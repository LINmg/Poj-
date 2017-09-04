#include <stdio.h>
#include <queue>
#include<algorithm>
using namespace std;
#define N 10000

struct _pair {
	int first, second;
};
_pair AB[N];
priority_queue<int>pque;
int n,L,P;
bool cmp(const _pair &a1, const _pair &a2)
{
	return a1.first<a2.first;
}

int main() {
	int i,ans=0,a;
	scanf("%d", &n);
	AB[0].first = 0;
	AB[0].second = 0;
	for (i = 1; i <= n; i++) {
		scanf(" %d %d", &AB[i].first, &AB[i].second);
	}
	scanf("%d %d", &L, &P);
	sort(AB, AB + n + 1,cmp);
	for (i = n; i >=0; i--) {
		a = L - AB[i].first;
		while (a > P ) {
			if (pque.empty()) {
				puts("-1");
				return 0;
			}
			P += pque.top();
			pque.pop();
			ans++;
		}
		pque.push(AB[i].second);
	}
	printf("%d\n", ans);
	return 0;
}