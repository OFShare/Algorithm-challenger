/*
 * Created by OFShare on 2020-01-23, 春节期间
 *
 */

#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>

const int maxn = 1e5 + 5;
struct node {
	int u, v;
	double w;
	bool operator<(const node &rhs) const {
		return w < rhs.w;
	}
}edges[maxn];

struct point {
	double x, y, z, r;
}p[maxn];

double len(const point &a, const point &b) {
	return std::sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z));
}

int fa[maxn];
int find_union(int x) {
	return x == fa[x]? x: fa[x] = find_union(fa[x]);
}

int n;
double dis[105][105];

int main() {
	while (scanf("%d", &n) && n) {
		for (int i = 1; i <= n; ++i) {
			scanf("%lf %lf %lf %lf", &p[i].x, &p[i].y, &p[i].z, &p[i].r);
		}
		int cnt = 0;	
		for (int i = 1; i <= n; ++i) {
			for (int j = i + 1; j <= n; ++j) {
				double d = len(p[i], p[j]);
				++cnt;
				edges[cnt].u = i;
				edges[cnt].v = j;
				edges[cnt].w = std::max(d - p[i].r - p[j].r, 0.0);
			}
		}

		int edgeNumber = 0;
		double ret = 0;	
		for (int i = 0; i <= n; ++i) {
			fa[i] = i;
		}
		std::sort(edges + 1, edges + 1 + cnt);	
		for (int i = 1; i <= cnt; ++i) {
			if (edgeNumber == n - 1)
				break;
			int u = edges[i].u, v = edges[i].v;
			double w = edges[i].w;
			int x = find_union(u);
			int y = find_union(v);
			if (x != y) {
				fa[x] = y;
				++edgeNumber;
				ret += w;	
			}		
		}
		printf("%.3lf\n", ret);	
	}
	return 0;
}
