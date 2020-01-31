/*
 * Created by OFShare on 2020-01-29, 春节期间
 *
 */ 

#include <bits/stdc++.h>

const int maxn = 1500 + 5;
int n;
std::set<std::string> st;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		char tmp[maxn];
		scanf("%s", tmp);
		std::string str(tmp);
		st.insert(str);
	}
	printf("%d\n", st.size());
	return 0;
}
