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
	int x, y;
}p[maxn];

double len(const point &a, const point &b) {
	return std::sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + 0.0);
}

int fa[maxn];
int find_union(int x) {
	return x == fa[x]? x: fa[x] = find_union(fa[x]);
}

int T, c;
double dis[105][105];

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &c);
		for (int i = 1; i <= c; ++i) {
			scanf("%d %d", &p[i].x, &p[i].y);
		}
		int cnt = 0;	
		for (int i = 1; i <= c; ++i) {
			for (int j = i + 1; j <= c; ++j) {
				double d = len(p[i], p[j]);
				if (d >= 10 && d <= 1000) {
					++cnt;
					edges[cnt].u = i;
					edges[cnt].v = j;
					edges[cnt].w = d * 100;
				}
			}
		}
		
		int edgeNumber = 0;
		double ret = 0;	
		for (int i = 0; i <= c; ++i) {
			fa[i] = i;
		}
		std::sort(edges + 1, edges + 1 + cnt);	
		for (int i = 1; i <= cnt; ++i) {
			if (edgeNumber == c - 1)
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
		if (edgeNumber == c - 1)
			printf("%.1lf\n", ret);	
		else 
			printf("oh!\n");

	}
	return 0;
}
