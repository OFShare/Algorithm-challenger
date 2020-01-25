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

int n;
int dis[105][105];
int main() {
	scanf("%d", &n);

	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			int w;
			scanf("%d", &w);
			dis[i][j] = w;
		}
	}
	int q;
	scanf("%d", &q);
	for (int i = 1; i <= q; ++i) {
		int u, v;
		scanf("%d %d", &u, &v);
		dis[u][v] = 0;
		dis[v][u] = 0;
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			++cnt;
			edges[cnt].u = i;
			edges[cnt].v = j;
			edges[cnt].w = dis[i][j];
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
	printf("%d\n", ret);	
	return 0;
}
