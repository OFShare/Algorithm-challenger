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
#include <cmath>
#include <cassert>

const int maxn = 5e6 + 5;
struct node {
	int u, v;
 	double	w;
	bool operator<(const node &rhs) const {
		return w < rhs.w;
	}
}edges[maxn];

struct point {
	int x, y;
}p[maxn];

int fa[maxn];
int find_union(int x) {
	return x == fa[x]? x: fa[x] = find_union(fa[x]);
}

double len(const point &a, const point &b) {
	return std::sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + 0.0);
}

int n, S, P;

int main() {
	scanf("%d", &n);
	while (n--) {
		scanf("%d %d", &S, &P);
		for (int i = 1; i <= P; ++i) {
			scanf("%d %d", &p[i].x, &p[i].y);
		}

		int cnt = 0;
		for (int i = 1; i <= P; ++i) {
			for (int j = i + 1; j <= P; ++j) {
				++cnt;
				edges[cnt].u = i;
				edges[cnt].v = j;
				edges[cnt].w = len(p[i], p[j]);
			}
		}

		int edgeNumber = 0;
		std::vector<double> vec;
		for (int i = 0; i <= P; ++i) {
			fa[i] = i;
		}
		std::sort(edges + 1, edges + 1 + cnt);

		for (int i = 1; i <= cnt; ++i) {
			if (edgeNumber == P - 1) {
				break;
			}
			int u = edges[i].u, v = edges[i].v;
			double w = edges[i].w;
			int x = find_union(u);
			int y = find_union(v);
			if (x != y) {
				fa[x] = y;
				++edgeNumber;
				vec.push_back(w);
			}
		}
	
		std::sort(vec.begin(), vec.end());
		S = std::min(S, P);
		printf("%.2lf\n", vec[P - 1 - (S - 1) - 1]);
	}

	return 0;
}
