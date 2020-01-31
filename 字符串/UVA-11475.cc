/*
 * Created by OFShare on 2020-01-30, 春节期间
 *
 */

#include <cstdio>
#include <cstring>
#include <string>

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
}hash, hash2;

int main() {
#ifdef Acui
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif

	while (scanf("%s", hash.str + 1) != EOF) {
		int len = strlen(hash.str + 1);
		for (int i = len, j = 1; i >= 1; --i) {
			hash2.str[j++] = hash.str[i];
		}
		hash2.str[len + 1] = '\0';

		hash.init();
		hash2.init();

		int pos;
		// 枚举最长后缀回文串的长度
		for (int i = len; i >= 1; --i) {
			if (hash.get(len - i + 1, len) == hash2.get(1, 1 + i - 1)) {
				pos = len - i + 1;
				break;	
			}
		}

		printf("%s", hash.str + 1);
		for (int i = pos - 1; i >= 1; --i) 
			putchar(hash.str[i]);
		printf("\n");
	}
	return 0;
}
