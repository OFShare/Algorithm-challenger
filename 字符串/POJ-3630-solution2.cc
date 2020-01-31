/*
 * Created by OFShare on 2020-01-28, 春节期间
 *
 */

#include <cstdio>
#include <cstring>

/* 字典树
 * child[1]['a'] = 3, 表示节点1和节点3有一条边值为'a'的边
 * total 是节点总个数
 * exist[5], 表示存在从根节点1到节点5构成的字符串这样的输入
 * CHAR 表示边的集合
 *
 * */

struct trie {
	static const int CHAR = 26, MAXN = 1e5 + 5;

	int total, child[MAXN][CHAR];
	int exist[MAXN];

	trie() {
		total = 0;
		// std::memset(exist, 0, sizeof exist);
		// std::memset(child, 0, sizeof child);
	}

	void insert(const char *str) {
		int len = strlen(str);
		int cur = 0;
		for (int i = 0; i < len; ++i) {
			int next = child[cur][str[i] - '0'];
			if (next == 0) 
				child[cur][str[i] - '0'] = ++total;
			cur = child[cur][str[i] - '0'];
		}
		exist[cur]++;	
	}	

	bool query(const char *str) {
		int cur = 0, len = strlen(str);
		for (int i = 0; i < len; ++i) {
			int next = child[cur][str[i] - '0'];
			if (exist[next] && (i + 1) < len)
				return true;
			cur = next;
		}
		return false;
	}
}tree, tmp_tree;

const int maxn = 1e5 + 5;
int t, n;
char tmp[maxn][15];

int main() {
	scanf("%d", &t);
	while (t--) {
		tree = tmp_tree;

		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%s", tmp[i]);
			tree.insert(tmp[i]);
		}

		bool is_consistent = true;
		for (int i = 1; i <= n; ++i) {
			if (tree.query(tmp[i])) {
				is_consistent = false; 
				break;
			}
		}

		if (is_consistent) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
