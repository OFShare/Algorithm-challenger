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
struct node {
	std::string str;
	bool operator<(const node &rhs) const {
		if (str == rhs.str)
			return false;
		return true;	
	}
};

int M, L;
char tmp[maxn];

int main() {
	while (scanf("%d %d", &M, &L) != EOF) {
		scanf("%s", tmp);
		std::string str = std::string(tmp);

		int ans = 0;
		// i < L 只枚举开头, 后面的用滑动窗口枚举
		for (int i = 0; i < L && i + M * L <= str.size(); ++i) {
			std::map<node, int> mp;
			// 窗口初始化, 第一个窗口	
			for (int j = i; j + L <= i + M * L; j += L) {
				node nd;
				nd.str = str.substr(j, L);
				mp[nd]++;
			}
			if (mp.size() == M)
				++ans;
			
			// 模拟窗口移动, 先删除前一个, 再加入后一个
			for (int j = i + M * L + L; j <= str.size(); j += L) {
				node nd;
				nd.str = str.substr(j - L - M * L, L);
				mp[nd]--;
				if (mp[nd] == 0)
					mp.erase(nd);

				nd.str = str.substr(j - L, L);
				mp[nd]++;
				if (mp.size() == M)
					++ans;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
