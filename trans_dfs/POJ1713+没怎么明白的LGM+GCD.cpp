#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
__int64 Gcd(__int64 a, __int64 b) {
	__int64 c;
	if (a < b) {
		c = a;    
		a = b;
		b = c;
	}
	while (b) {
		c = b;
		b = a%b;
		a = c;
	}
	return a;
}
__int64 LCM(__int64 x1, __int64 x2) {
	__int64 c = Gcd(x1, x2);
	return x1*x2 / c;
}
int main() {
	__int64 cas, c1, c2, t1;
	__int64 t2, p, k, m, n, h;
	cin >> cas;
	while (cas--) {
		scanf("%I64d/%I64d", &c1, &t1);
		scanf("%I64d/%I64d", &c2, &t2);
		k = t1 * t2;
		m = t2 * c1;
		n = t1 * c2;
		p = LCM(m, n);
		h = Gcd(p, k);
		if (h == k) {
			printf("%I64d\n", p / h);
		}
		else {
			printf("%I64d/%I64d\n", p / h, k / h);
		}
	}
	return 0;
}