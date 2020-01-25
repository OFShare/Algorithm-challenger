/*
 * Created by OFShare on 2020-01-23, 春节期间
 *
 */

#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

using std::priority_queue;
using std::vector;
using std::greater;
using std::pair;

const int maxn = 1e5 + 5;

bool vis[maxn];
int cnt = 0, head[maxn];
struct node {
	int v, w, next;
}Edges[maxn];

void addEdge(int u, int v, int w) {
	++cnt;
	Edges[cnt].v = v;
	Edges[cnt].w = w;
	Edges[cnt].next = head[u];
	head[u] = cnt;
}

int n;
int dis[maxn];
int prim(int _start) {
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<std::pair<int, int> > > que;
	dis[_start] = 0;
	que.push({dis[_start], _start});

	int nodeNumber = 0, ret = 0;
	while (!que.empty() && nodeNumber != n) {
		int d = que.top().first, u = que.top().second;
		que.pop();

		if (vis[u])
			continue;
		vis[u] = true;
		nodeNumber++;
		ret += d;
		for (int i = head[u]; i != -1; i = Edges[i].next) {
			int v = Edges[i].v, w = Edges[i].w;
			if (w < dis[v]) {
				dis[v] = w;
				que.push({dis[v], v});
			}
		}
	}

	return ret;
}

int main() {
	while (scanf("%d", &n) && n) {
		cnt = 0;
		std::memset(head, -1, sizeof head);
		std::memset(dis, 0x3f3f3f, sizeof dis);
		std::memset(vis, 0, sizeof vis);

		for (int i = 1; i <= n * (n - 1) / 2; ++i) {
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			addEdge(u, v, w);
			addEdge(v, u, w);
		}
		printf("%d\n", prim(1));
	}
	return 0;
}
