/*
 * Created by OFShare on 2020-01-23, 春节期间
 *
 */

#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <set>

const int maxn = 5e6 + 5;
struct node {
	int u, v, w;
	bool operator<(const node &rhs) const {
		return w < rhs.w;
	}
}edges[maxn];

int fa[maxn];
int find_union(int x) {
	return x == fa[x]? x: fa[x] = find_union(fa[x]);
}

int n;
char str[maxn][10];

int len(char* lhs, char* rhs) {
	int ret = 0;
	for (int i = 0; i < 7; ++i) {
		if (lhs[i] != rhs[i])
			++ret;
	}
	return ret;
}

int main() {
	while (scanf("%d", &n) && n) {
		for (int i = 1; i <= n; ++i) {
			scanf("%s", str[i]);
		}

		int cnt = 0;
		for (int i = 1; i <= n; ++i) {
			for (int j = i + 1; j <= n; ++j) {
				++cnt;
				edges[cnt].u = i;
				edges[cnt].v = j;
				edges[cnt].w = len(str[i], str[j]);
			}
		}

		int edgeNumber = 0, ret = 0;
		for (int i = 0; i <= n; ++i) {
			fa[i] = i;
		}
		std::sort(edges + 1, edges + 1 + cnt);	
		for (int i = 1; i <= cnt; ++i) {
			if (edgeNumber == n - 1)
				break;
			int u = edges[i].u, v = edges[i].v, w = edges[i].w;
			int x = find_union(u);
			int y = find_union(v);
			if (x != y) {
				fa[x] = y;
				++edgeNumber;
				ret += w;
			}		
		}

		printf("The highest possible quality is 1/%d.\n", ret);
	}

	return 0;
}
