#include<iostream>
#include<math.h>
#include<iomanip>

using namespace std;

int main() {
	double t, d, h, a1, a2;
	char c1, c2;
	while (cin>>c1 &&c1!='E') {
		cin >> a1 >> c2 >> a2;
		if (c1 == 'T'&&c2=='D'|| c1 == 'D'&&c2 == 'T') {
			if (c1 == 'T') t = a1,d=a2;
			else t = a2, d = a1;
			h = t + 0.5555*(6.11*exp(5417.7530*((1 / 273.16) - (1 / (d + 273.16)))) - 10.0);
		}
		else if (c1 == 'T'&&c2 == 'H' || c1 == 'H'&&c2 == 'T') {
			if (c1 == 'T') t = a1, h = a2;
			else t = a2, h = a1;
			d=  1 / (1 / 273.16 - log(((h-t) / 0.5555 + 10.0) / 6.11) / 5417.7530) - 273.16;
		}
		else {
			if (c1 == 'D') d = a1, h = a2;
			else d = a2, h = a1;
			t = h - 0.5555*(6.11*exp(5417.7530*((1 / 273.16) - (1 / (d + 273.16)))) - 10.0);
		}
		cout <<setiosflags(ios::fixed)<<setprecision(1)<< "T " << t << " D " << d << " H " << h << endl;
	}
	return 0;
}