/*
 * Created by OFShare on 2019-10-21
 *
 */

#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>

const int INF = 1e9;
const int maxn = 5e4 + 5;
int t, n;
// 记录每个结点的相邻结点有那些, 无根树-->有根树
std::vector<int> G[maxn];
// vis[i]: 结点i是否访问过了
bool vis[maxn];

// 记录每个结点的父亲结点, 最开始初始化为fa[i] = i, 方便找到树的根
int fa[maxn];
// 记录每个结点的儿子结点
std::vector<int> sons[maxn];
// A[i]: 记录删除结点i后, 最大的子树的结点个数
int A[maxn];
// 记录最大子树结点的最小值
int ans;

// 以结点rt建树
void build_tree(int rt) {
    vis[rt] = true;
    for (int i = 0; i < G[rt].size(); ++i) {
        int son = G[rt][i];
        // 没有访问过, 结点rt找到一个儿子结点
        if (!vis[son]) {
            sons[rt].push_back(son);
            build_tree(son);
        }
    }
}

// 以结点rt为根的子树所含有的结点个数
int dp[maxn];
int dfs(int rt) {
    // 记忆化
    if (dp[rt] != -1)
        return dp[rt];
    // 递归的边界, 也要更新A[rt]
    if (sons[rt].size() == 0) {
        A[rt] = std::max(A[rt], n - 1);
        return 1;
    }
    int sum = 1;
    for (int i = 0; i < sons[rt].size(); ++i) {
        int son = sons[rt][i];
        sum += dfs(son);
        A[rt] = std::max(A[rt], dfs(son));
    }
    // 结点rt的上方结点个数为n - sum
    A[rt] = std::max(A[rt], n - sum);
    ans = std::min(ans, A[rt]);
    return dp[rt] = sum;
}

int main() {
#ifdef Acui
    freopen("datain.txt", "r", stdin);
    freopen("dataoutMy.txt", "w", stdout);
#endif
    scanf("%d", &n);
    // 初始化
    ans = INF;
    for (int i = 1; i <= n; ++i) {
        fa[i] = i;
        sons[i].clear();
        G[i].clear();
        A[i] = 0;
        dp[i] = -1;
        vis[i] = false;
    }
    for (int i = 1; i <= n - 1; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    // 任选一个结点为根, 无根树转有根树
    int root = 1;
    build_tree(root);
    dfs(root);
    std::vector<int> numbers;
    for (int i = 1; i <= n; ++i) {
        if (A[i] == ans) {
            numbers.push_back(i);
        }
    }
    for (int i = 0; i < numbers.size(); ++i) {
        if (i == 0) {
            printf("%d", numbers[i]);
            continue;
        }
        printf(" %d", numbers[i]);
    }
    printf("\n");
    return 0;
}
