/*
 * Created by OFShare on 2020-01-24, 春节期间
 *
 */

#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <cstring>
#include <algorithm>

const int maxn = 100 + 5;
const int dirx[] = {1, 0, -1, 0};
const int diry[] = {0, 1, 0, -1};

int t, row, col;
int number = 0;
char mp[maxn][maxn];

struct node {
	int u, v, w;
	bool operator<(const node &rhs) const {
		return w < rhs.w;
	}
}edges[maxn * maxn];

struct point {
	int x, y;
	int step;
	point() {}
	point(int x_, int y_, int step_ = 0): x(x_), y(y_), step(step_) {}
	bool operator<(const point &rhs) const {
		return std::vector<int> {x, y} < std::vector<int> {rhs.x, rhs.y};
	}
};

bool vis[maxn][maxn];
// std::map<point, int> ids;
int ids[maxn][maxn];

void bfs(point _start) {
	std::queue<point> que;
	que.push(_start);
	
	int src = ids[_start.x][_start.y];

	while (!que.empty()) {
		point p = que.front();
		que.pop();
	
		int x = p.x, y = p.y, step = p.step;
		if (mp[x][y] == 'A' || mp[x][y] == 'S') {
			int dst = ids[x][y];
			if (src != dst) {
				++number;
				edges[number].u = src;
				edges[number].v = dst;
				edges[number].w = step;
			}
		}
		vis[x][y] = true;

		for (int i = 0; i < 4; ++i) {
			int newx = x + dirx[i], newy = y + diry[i];
			if (newx >= 1 && newx <= row && newy >= 1 && newy <= col && !vis[newx][newy] && 
					(mp[newx][newy] == 'A' || mp[newx][newy] == 'S' || mp[newx][newy] == ' ')) {
				que.push(point(newx, newy, step + 1));
				// 对加入队列的设置true, 这样可以避免大量相同状态的结点都入了队列
				vis[newx][newy] = true;
			}
		}
	}
}

int fa[maxn * maxn];
int find_union(int x) {
	return x == fa[x]? x: fa[x] = find_union(fa[x]);
}

char tmp[55];
int main() {
#ifdef Acui
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif 
	fgets(tmp, 55, stdin);
	sscanf(tmp, "%d", &t);

	while (t--) {
		number = 0;
		// ids.clear();
		fgets(tmp, 55, stdin);
		sscanf(tmp, "%d %d", &col, &row);
		for (int i = 1; i <= row; ++i) 
			fgets(mp[i] + 1, 55, stdin);

		int id = 0;
		for (int i = 1; i <= row; ++i) {
			for (int j = 1; j <= col; ++j) {
				if (mp[i][j] == 'A' || mp[i][j] == 'S') {
					// ids[point(i, j)] = ++id;
					ids[i][j] = ++id;
				}
			}
		}
		
		for (int i = 0; i <= id; ++i)
			fa[i] = i;
		for (int i = 1; i <= row; ++i) {
			for (int j = 1; j <= col; ++j) {
				if (mp[i][j] == 'A' || mp[i][j] == 'S') {
					std::memset(vis, 0, sizeof vis);
					point s = point(i, j, 0);
					bfs(s);
				}
			}
		}
	
		int edgeNumber = 0, ret = 0;
		std::sort(edges + 1, edges + 1 + number);
		for (int i = 1; i <= number; ++i) {
			if (edgeNumber == id - 1)
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
