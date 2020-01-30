/*
 * Created by OFShare on 2020-01-30, 春节期间
 *
 */ 

#include <bits/stdc++.h>

/*
 * 题意：给定若干个长度≤1e6的字符串，询问每个字符串最多是由多少个相同的子字符串重复连接而成的。
 * 如：ababab 则最多有 3 个 ab 连接而成。
 *
 * 题解: 从第一个字符开始枚举循环节可能的长度k(1<=k<=n), 如果所枚举的长度k是长度n的因数
 * 就走进check函数判断s[1]~s[k]所组成的字符串是否可以作为**循环节**
 *
 *
 */

/*  **字符串Hash**
 *  
 *  为了方便处理, 字符串下标都是从1开始
 *  使用ull可以方便的自然溢出, H和P数组
 *  如何理解这段代码, 我们采用类比的方式
 *  取得区间[L, R]构成的字符串的hash值
 *  对于123456, 我们想取3456这个子串, 3456 = 123456 - 12 * std::pow(base, 4), 在十进制下base为10
 *  P[0] = base ^ 0, P[1] = base ^ 1, P[2] = base ^ 2, 类似于std::pow(base, 4), 不用std::pow是为了自然溢出
 *  H[i]表示的是1 ~ i构成的字符串的hash值, 如H[0] = 0, H[3] = 123, H[5] = 12345 
 *  
 *  H[i]表示前缀hash值
 *  P[i]表示base的i次方
*/

struct Hash {
	typedef unsigned long long ull;
	static const int maxn = 1e6 + 5;
	// 31 131 1313 13131 131313 etc..
	static const int base = 1e9 + 7;
	char str[maxn];
	ull h[maxn], p[maxn];

	void init() {
		h[0] = 0;
		p[0] = 1;
		int len = strlen(str + 1);

		for (int i = 1; i <= len; ++i) {
			h[i] = h[i - 1] * base + str[i];
			p[i] = p[i - 1] * base;
		}
	}

	ull get(int L, int R) {
		return h[R] - h[L - 1] * p[R - L + 1];
	}
}hash;

typedef unsigned long long ull;
bool check(int i, int k, int len) {
	ull pre = hash.get(i, i + k - 1);
	int j = i + k;
	while (j <= len) {
		ull cur = hash.get(j, j + k -1);
		if (pre != cur) return false;
		pre = cur;
		j += k;
	}
	return true;
}

int main() {
	while (scanf("%s", hash.str + 1)) {
		if (hash.str[1] == '.') break;
		hash.init();
		
		int len = strlen(hash.str + 1);
		for (int i = 1; i <= len; ++i) {
			if (len % i != 0) continue;
			if (check(1, i, len)) {
				printf("%d\n", len / i);
				break;
			}
		}
	}	
	return 0;
}
