/*
 * Created by OFShare on 2020-01-28, 春节期间
 *
 */

#include <cstdio>
#include <cstring>
#include <string>

/* 字典树
 * child[1]['a'] = 3, 表示节点1和节点3有一条边值为'a'的边
 * total 是节点总个数
 * exist[5], 表示存在从根节点0到节点5构成的字符串
 * CHAR 表示边的集合
 * 
 * */

struct trie {
	static const int CHAR = 26, MAXN = 5e5 + 5;
	static const char base = 'a';

	int total, child[MAXN][CHAR];
	int exist[MAXN];

	trie() {
		total = 0;
		// std::memset(exist, 0, sizeof exist);
		// std::memset(child, 0, sizeof child);
	}

	void insert(const char *str, int len) {
		int cur = 0;
		for (int i = 0; i < len; ++i) {
			int next = child[cur][str[i] - base];
			if (next == 0) 
				child[cur][str[i] - base] = ++total;
			cur = child[cur][str[i] - base];
			exist[cur]++;
		}
	}

	int query(const char *str, int len) {
		int cur = 0;
		for (int i = 0; i < len; ++i) {
			int next = child[cur][str[i] - base];
			if (next == 0)
				return 0;
			cur = next;
		}
		return exist[cur];
	}	

}tree, tmp_tree;

const int maxn = 5e5 + 5;
char tmp[maxn];

int main() {
#ifdef Acui
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif

	while (fgets(tmp, maxn - 1, stdin)) {
		if (strlen(tmp) == 1)
			break;
		tree.insert(tmp, strlen(tmp) - 1);
	}
	while (fgets(tmp, maxn - 1, stdin)) {
		printf("%d\n", tree.query(tmp, strlen(tmp) - 1));
	}
	return 0;
}
