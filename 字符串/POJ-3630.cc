/*
 * Created by OFShare on 2020-01-26, 春节期间
 *
 */

#include <cstdio>
#include <cstring>

/* 字典树
 * child[1]['a'] = 3, 表示节点1和节点3有一条边值为3的边
 * tatal 是节点总个数
 * is_exist[5], 表示存在从根节点1到节点5构成的字符串这样的输入
 * CHAR 表示边的集合
 *
 * */

struct Trie {
	static const int CHAR = 26, MAXN = 1e5 + 5;

	int total, root, child[MAXN][CHAR];
	bool is_exist[MAXN];

	Trie() {
		std::memset(child[1], 0, sizeof child[1]);
		std::memset(is_exist, 0, sizeof is_exist);
		root = total = 1;
	}

	void Insert(const char *str) {
		int *cur = &root;
		for (const char *p = str; *p; p++) {
			cur = &child[*cur][*p - '0'];
			if (*cur == 0) {
				*cur = ++total;
				memset(child[total], 0, sizeof child[total]);
				is_exist[total] = false;
			}
		}
		is_exist[*cur] = true;
	}

	bool Query(const char *str) {
		int *cur = &root;
		for (const char *p = str; *p && *cur; p++)
			cur = &child[*cur][*p - '0'];
		return (*cur) && is_exist[*cur];
	}

	bool find_another_prefix(const char *str) {
		int *cur = &root;
		for (const char *p = str; *p && *cur; ++p) {
			cur = &child[*cur][*p - '0'];
			if (is_exist[*cur] && *(p + 1))
				return true;
		}
		return false;
	}
}tree, tmp_tree;

const int maxn = 1e4 + 5;
int t, n;
char tmp[maxn][15];

int main() {
	scanf("%d", &t);
	while (t--) {
		tree = tmp_tree;

		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%s", tmp[i]);
			tree.Insert(tmp[i]);
		}

		bool is_consistent = true;
		for (int i = 1; i <= n; ++i) {
			if (tree.find_another_prefix(tmp[i])) {
				is_consistent = false; 
				break;
			}
		}

		if (is_consistent) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
