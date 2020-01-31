/*
 * Created by OFShare on 2020-01-29, 春节期间
 *
 */ 

#include <bits/stdc++.h>

const int maxn = 1500 + 5;

typedef unsigned long long ull;
ull base = 1e9 + 7;
ull H[maxn], P[maxn];
// 字符串从下标1开始
void Hash(const char *str, int len) {	
	H[0] = 0;
	// 用状态H[i]去更新状态H[i + 1]
	for (int i = 0; i < len; ++i) {
		H[i + 1] = H[i] * base + str[i + 1];	
	}

	P[0] = 1;
	for (int i = 1; i <= len; ++i) 
		P[i] = P[i - 1] * base;	
}

// 为了方便处理, 字符串下标都是从1开始
// 使用ull可以方便的自然溢出, H和P数组
// 如何理解这段代码, 我们采用类比的方式
// 对于123456, 我们想取3456这个字串, 3456 = 123456 - 12 * std::pow(base, 4), 在十进制下base为10
// P[0] = base ^ 0, P[1] = base ^ 1, P[2] = base ^ 2, 类似于std::pow(base, 4), 不用std::pow是为了自然溢出
// H[i]表示的是1 ~ i构成的字符串的hash值, 如H[3] = 123, H[5] = 12345 

// 取得区间[L, R]构成的字符串的hash值
ull getHash(int L, int R) {
	return H[R] - H[L - 1] * P[R - L + 1];
}

int n;
std::set<ull> st;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		char tmp[maxn];
		scanf("%s", tmp + 1);
		int len = strlen(tmp + 1);
		Hash(tmp + 1, len);

		ull ret1 = H[len];
		ull ret2 = getHash(1, len);
		assert(ret1 == ret2);

		st.insert(ret1);
	}
	printf("%d\n", (int)st.size());
	return 0;
}
