/*
 * Created by OFShare on 2020-01-23, 春节期间
 *
 */

#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

const int maxn = 1e5 + 5;
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

int P, R;
int main() {
	while (scanf("%d", &P) && P) {
		scanf("%d", &R);

		int cnt = 0;
		for (int i = 1; i <=R; ++i) {
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			++cnt;
			edges[cnt].u = u;
			edges[cnt].v = v;
			edges[cnt].w = w;
		}

		int edgeNumber = 0, ret = 0;	
		for (int i = 0; i <= P; ++i) {
			fa[i] = i;
		}
		std::sort(edges + 1, edges + 1 + cnt);	
		for (int i = 1; i <= cnt; ++i) {
			if (edgeNumber == P - 1)
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
		printf("%d\n", ret);	
	}
	return 0;
}
