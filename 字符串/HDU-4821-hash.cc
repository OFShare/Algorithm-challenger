/*
 * Created by OFShare on 2020-01-25, 春节期间
 *
 */

#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <map>

const int maxn = 1e5 + 5;

// 其中seed是顺便选择的基数
// 对一个串通过init_left, init_right的预处理后,就用get_hash(i,L)可以得到从位置i开始的,长度为L的子串的hash值.
// seed: 31 131 1313 13131 131313 etc.
const int seed = 131; 
typedef unsigned long long ull;

ull hashLeft[maxn], hashRight[maxn];

void init_left() {
	hashLeft[0] = 1;
	for (int i = 1; i < maxn; i++)
		hashLeft[i] = hashLeft[i - 1] * seed;
}

void init_right(const char* str) {
	int len = strlen(str);
	hashRight[len] = 0;
	for (int i = len - 1; i >= 0; --i) {
		hashRight[i] = hashRight[i + 1] * seed + (str[i] - 'a' + 1);
	}
}

ull get_hash(int i,int L) {
	return hashRight[i] - hashRight[i + L] * hashLeft[L];
}

int M, L;
char tmp[maxn];

int main() {
	init_left();
	while (scanf("%d %d", &M, &L) != EOF) {
		scanf("%s", tmp);
		std::string str = std::string(tmp);
		init_right(tmp);

		int ans = 0;
		// i < L 只枚举开头, 后面的用滑动窗口枚举
		for (int i = 0; i < L && i + M * L <= str.size(); ++i) {
			std::map<ull, int> mp;
			// 窗口初始化, 第一个窗口	
			for (int j = i; j + L <= i + M * L; j += L) {
				ull d = get_hash(j, L);
				mp[d]++;
			}
			if (mp.size() == M)
				++ans;

			// 模拟窗口移动, 先删除前一个, 再加入后一个
			for (int j = i + M * L + L; j <= str.size(); j += L) {
				ull d = get_hash(j - L - M * L, L);
				mp[d]--;
				if (mp[d] == 0) 
					mp.erase(d);

				d = get_hash(j - L, L);
				mp[d]++;
				if (mp.size() == M)
					++ans;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
