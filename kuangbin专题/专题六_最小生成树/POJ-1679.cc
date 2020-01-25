/*
 * Created by OFShare on 2020-01-24, 春节期间
 *
 */

#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

const int INF = 1e9;
const int maxn = 1e5 + 5;

struct node {
	int u, v, w;
	bool is_chosen;
	bool operator<(const node &rhs) const {
		return w < rhs.w;
	}
}edges[maxn];

int fa[maxn];
std::vector<int> vec[maxn];
int dis[105][105];
int find_union(int x) {
	return x == fa[x]? x: fa[x] = find_union(fa[x]);
}

int t, n, m;
int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= m; ++i) {
			scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
			edges[i].is_chosen = false;
		}
		for (int i = 0; i <= n; ++i) {
			fa[i] = i;
			vec[i].clear();
			vec[i].push_back(i);
		}
	
		int edgeNumber = 0, MST1 = 0;	
		std::sort(edges + 1, edges + 1 + m);
		for (int i = 1; i <= m; ++i) {
			if (edgeNumber == n - 1)
				break;
			int u = edges[i].u, v = edges[i].v, w = edges[i].w;
			int x = find_union(u);
			int y = find_union(v);
			if (x != y) {
				MST1 += w;
				++edgeNumber;
				edges[i].is_chosen = true;
				for (int k1 = 0; k1 < vec[x].size(); ++k1) {
					for (int k2 = 0; k2 < vec[y].size(); ++k2) {
						int node1 = vec[x][k1];
						int node2 = vec[y][k2];
						dis[node2][node1] = dis[node1][node2] = w;
					}
				}
				// 将x为根的子树的所有节点, 加入到以y为根的子树中去
				fa[x] = y;
				for (int k1 = 0; k1 < vec[x].size(); ++k1) {
					int node1 = vec[x][k1];
					vec[y].push_back(node1);
				}		
			}
		}

		int MST2 = INF;
		for (int i = 1; i <= m; ++i) {
			if (edges[i].is_chosen == false) {
				int u = edges[i].u, v = edges[i].v, w = edges[i].w;
				MST2 = std::min(MST2, MST1 + w - dis[u][v]);
			}
		}
		// printf("####%d, %d\n", MST1, MST2);	
		if (MST1 == MST2) printf("Not Unique!\n");
		else printf("%d\n", MST1);
	}
	return 0;
}
