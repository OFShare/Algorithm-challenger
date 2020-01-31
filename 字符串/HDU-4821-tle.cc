/*
 * Created by OFShare on 2020-01-25, 春节期间
 *
 */

#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <set>

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
		for (int i = 0; i + M * L <= str.size(); ++i) {
			std::set<node> st;
			std::string middle = str.substr(i, M * L);
			for (int j = 0; j + L <= middle.size(); j += L) {
				node nd;
				nd.str = middle.substr(j, L);
				st.insert(nd);
			}
			if (st.size() == M)
				++ans;
		}
		printf("%d\n", ans);
	}
	return 0;
}
