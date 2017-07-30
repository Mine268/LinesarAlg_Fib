#include "stdio.h"

// 斐波那契数列的线性代数求法，最多输出前90项，最开头的两项省略
// 刘多要是又装逼就拿这个轰死他
// 稳!

struct Matrix {
	long long m[2][2];
	Matrix() {
		m[0][0] = 0; m[0][1] = 0; m[1][0] = 0; m[1][1] = 0;
	}
};

struct Matrix times(struct Matrix m1, struct Matrix m2) {
	struct Matrix res;
	res.m[0][0] = m1.m[0][0] * m2.m[0][0] + m1.m[0][1] * m2.m[1][0];
	res.m[0][1] = m1.m[0][0] * m2.m[0][1] + m1.m[0][1] * m2.m[1][1];
	res.m[1][0] = m1.m[1][0] * m2.m[0][0] + m1.m[1][1] * m2.m[1][0];
	res.m[1][1] = m1.m[1][0] * m2.m[0][1] + m1.m[1][1] * m2.m[1][1];
	return res;
}

struct Matrix qP(struct Matrix mtx, int b) {
	struct Matrix base = mtx, ori = mtx, ans = mtx;
	while(b != 0) {
		if(b & 1 == 1)
			ans = times(base, ans);
		base = times(base, base);
		b >>= 1;
	}
	return ans;
}

int main() {
	struct Matrix Trans, DTrans;
	struct Matrix Origi;
	Trans.m[0][0] = 1; Trans.m[0][1] = 1; Trans.m[1][0] = 1;
	Origi.m[0][0] = 1; Origi.m[1][0] = 1;

	int n; scanf("%d", &n);
	int i = 1;
	for(i = 1; i <= n; i++) {
		DTrans = qP(Trans, i);
		printf("%lld ", times(DTrans, Origi).m[1][0]);
	}

	return 0;
}
