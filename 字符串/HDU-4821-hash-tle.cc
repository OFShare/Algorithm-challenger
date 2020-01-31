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
typedef unsigned long long ull;

ull xp[maxn],hash[maxn];

void init()
{
	xp[0]=1;
	for(int i=1;i<maxn;i++)
		xp[i]=xp[i-1]*175;
}

ull get_hash(int i,int L)
{
	return hash[i]-hash[i+L]*xp[L];
}

int M, L;
char tmp[maxn];

int main() {
	init();
	while (scanf("%d %d", &M, &L) != EOF) {
		scanf("%s", tmp);
		std::string str = std::string(tmp);

		int n = strlen(tmp);
		hash[n] = 0;
		for(int i = n - 1; i >= 0; i--)
		{
			hash[i] = hash[i+1] * 175 + (str[i]-'a'+1);
		}
		// std:: cout << get_hash(0, 3) << std::endl;
		// std:: cout << get_hash(3, 3) << std::endl;
		// std:: cout << get_hash(6, 3) << std::endl;
		// std:: cout << get_hash(9, 3) << std::endl;
		// std:: cout << get_hash(1, 3) << std::endl;
		// std:: cout << get_hash(2, 3) << std::endl;
		// continue;

		int ans = 0;
		for (int i = 0; i + M * L <= str.size(); ++i) {
			std::set<ull> st;
			for (int j = i; j < i + M * L; j += L) {
				ull d = get_hash(j, L);
				st.insert(d);
			}
			if (st.size() == M)
				++ans;
		}
		printf("%d\n", ans);
	}
	return 0;
}
