/*
 * Created by OFShare on 2020-01-29, 春节期间
 *
 */

#include <cstdio>
#include <cstring>
#include <string>
#include <cassert>

const int maxn = 1e3 + 5;

typedef unsigned long long ull;
ull base = 13131;
ull H[maxn], P[maxn];
ull H2[maxn];

// 字符串从下标1开始
void Hash(const char *str, int len, ull *H) {
	H[0] = 0;
	P[0] = 1;
	for(int i = 1; i <= len; ++i) {
		H[i] = H[i - 1] * base + str[i];
		P[i] = P[i - 1] * base;
	}
}

// 取得区间[L, R]构成的字符串的hash值
ull getHash(int L, int R) {
	return H[R] - H[L - 1] * P[R - L + 1];
}

ull getHash2(int L, int R) {
	return H2[R] - H2[L - 1] * P[R - L + 1];
}

char str[maxn];

// 二分长度, 奇数, index是中心
int query(int index, int len1, int len2) {
	if (len1 < 1) 
		return 0;
	// [L, R)
	int L = 0, R = len1 + 1;

	for (int i = 0; i < 50; ++i) {
		int mid = (L + R) >> 1;
		if (getHash(index - mid, index + mid) == getHash2(len2 + 1 - index - mid, len2 + 1 - index + mid))
			L = mid;
		else 
			R = mid;	
	}
	return L;	
}

// 二分长度, 偶数, index, index + 1
int query2(int index, int len1, int len2) {
	if (len1 < 1) 
		return 0;
	// [L, R)
	int L = 0, R = len1 + 1;

	for (int i = 0; i < 50; ++i) {
		int mid = (L + R) >> 1;
		if (getHash(index - mid, index + 1 + mid) == getHash2(len2 + 1 - index -1 - mid, len2 + 1 - index + mid))
			L = mid;
		else 
			R = mid;	
	}
	return L;	
}

int main() {
	scanf("%s", str + 1);
	int len = strlen(str + 1);
	
	Hash(str, len, H);

	// 反转
	char str2[maxn];
	for (int i = len, j = 1; i >= 1; --i)
		str2[j++] = str[i];
	str2[len + 1] = '\0';
	Hash(str2, len, H2);
	
	int ans = 0;
	for (int i = 1; i <= len; ++i) {
		int d = query(i, std::min(i - 1, len - i), len);
		ans += d;
		if (i + 1 <= len && str[i] == str[i + 1])
			ans += query2(i, std::min(i - 1, len - i), len) + 1;
	}
	printf("%d\n", ans + len);
	return 0;
}
