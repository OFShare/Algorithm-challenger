/*
 * Created by OFShare on 2020-01-24, 春节期间
 *
 */

#include <cstdio>
#include <algorithm>
#include <cmath>

const int maxn = 750 * 750 + 5;
struct node {
	int u, v;
	double w;
	bool is_chosen;
	bool operator<(const node &rhs) const {
		return w < rhs.w;
	}
}edges[maxn];

struct point {
	int x, y;
}p[755];

double len(const point &a, const point &b) {
	return std::sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + 0.0);
}

int fa[755];
int find_union(int x) {
	return x == fa[x]? x: fa[x] = find_union(fa[x]);
}
int n, m;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d %d", &p[i].x, &p[i].y);
	}

	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			++cnt;
			edges[cnt].u = i;
			edges[cnt].v = j;
			edges[cnt].w = len(p[i], p[j]);
			edges[cnt].is_chosen = false;
		}
	}
	scanf("%d", &m);
	for (int i = 1; i <= m; ++i) {
		int u, v;
		scanf("%d %d", &u, &v);
		++cnt;
		edges[cnt].u = u;
		edges[cnt].v = v;
		edges[cnt].w = 0.0;
		edges[cnt].is_chosen = false;
	}

	int edgeNumber = 0;
	std::sort(edges + 1, edges + 1 + cnt);
	for (int i = 0; i <= n; ++i) 
		fa[i] = i;
	for (int i = 1; i <= cnt; ++i) {
		int u = edges[i].u, v = edges[i].v;
		double w = edges[i].w;
		int x = find_union(u);
		int y = find_union(v);
		if (x != y) {
			fa[x] = y;
			++edgeNumber;
			if (w > 0)
				edges[i].is_chosen = true;
		}
	}
	for (int i = 1; i <= cnt; ++i) {
		if (edges[i].is_chosen) {
			printf("%d %d\n", edges[i].u, edges[i].v);
		}
	}
	return 0;
}
