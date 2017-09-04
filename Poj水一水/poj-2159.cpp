#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	char s[101],a[26], b[26];
	cin >> s;
	for (int i = 0; s[i]; i++) a[s[i] - 'A']++;
	cin >> s;
	for (int i = 0; s[i]; i++) b[s[i] - 'A']++;
	sort(a,a+26);
	sort(b,b+26);
	for (int i = 0; i < 26; i++)
	{
		if (a[i] != b[i]) {
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	return 0;
}
//#include<iostream>
//#include<algorithm>
//using namespace std;
//char t1[26], t2[26], s[101];
//int main(void)
//{
//	cin >> s;
//	for (int i = 0; s[i]; i++)  t1[s[i] - 'A']++;
//	cin >> s;
//	for (int i = 0; s[i]; i++) t2[s[i] - 'A']++;
//	sort(t1, t1 + 26);
//	sort(t2, t2 + 26);
//	for (int i = 0; i < 26; i++)
//	{
//		if (t1[i] != t2[i])
//		{
//			cout << "NO\n";
//			return 0;
//		}
//	}
//	cout << "YES\n";
//	return 0;
//}