/*
 * Created by OFShare on 2019-10-20
 *
 */

#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <string>

const int maxn = 2e2 + 5;
int n;
// name ---> count
std::map<std::string, int> mp;

// sons[i]: 记录结点i的儿子结点有那些
std::vector<int> sons[maxn];
// dp[i][0]: 不选结点i. dp[i][1]: 选结点i. 能获得的最大独立点集
// unique[i][0]: 不选结点i. unique[i][1]: 选结点i. 在获得最大值的前提下, 是否唯一
int dp[maxn][2];
bool unique[maxn][2];

// 以结点rt为根的子树, 选择/不选rt时, 能获得的最大独立点集
int dfs(int rt, bool is_choose) {
    // 记忆化
    if (dp[rt][is_choose] != -1)
        return dp[rt][is_choose];
    // 递归的边界
    if (sons[rt].size() == 0) {
        // 选和不选都是唯一的
        unique[rt][is_choose] = true;
        if (is_choose)
            return 1;
        else
            return 0;
    }
    // 选择结点rt, 那么它的儿子结点都不能选
    if (is_choose) {
        int sum = 1;
        bool uniq = true;
        for (int i = 0; i < sons[rt].size(); ++i) {
            int son = sons[rt][i];
            sum += dfs(son, 0);
            // 只要有一个儿子结点不唯一, 则结点rt也不唯一
            if (unique[son][0] == false)
                uniq = false;
        }
        unique[rt][1] = uniq;
        return dp[rt][is_choose] = sum;
    }
    // 不选结点rt, 那么它的儿子结点都可以选或者不选
    else {
        int sum = 0;
        bool uniq = true;
        for (int i = 0; i < sons[rt].size(); ++i) {
            int son = sons[rt][i];
            sum += std::max(dfs(son, 0), dfs(son, 1));
            // 不选和选相等, 则不唯一
            if (dfs(son, 0) == dfs(son , 1))
                uniq = false;
            // 较大的那个不唯一, 则结点rt也不唯一
            if (dfs(son, 0) > dfs(son, 1) && unique[son][0] == false)
                uniq = false;
            if (dfs(son, 1) > dfs(son, 0) && unique[son][1] == false)
                uniq = false;
        }
        unique[rt][0] = uniq;
        return dp[rt][is_choose] = sum;
    }
}

int main() {
    while (scanf("%d", &n) != EOF && n) {
        // 初始化
        // 给结点编号
        int cnt = 0;
        mp.clear();
        for (int i = 1; i <= n; ++i) {
            sons[i].clear();
            dp[i][0] = -1;
            dp[i][1] = -1;
        }

        char name[101], name2[101];
        scanf("%s", name);
        std::string tmp_name(name);
        // 新的结点
        if (mp.find(tmp_name) == mp.end())
            mp[tmp_name] = ++cnt;
        //根结点的编号
        int root = cnt;

        for (int i = 1; i <= n - 1; ++i) {
            scanf("%s %s", name, name2);
            std::string tmp_name1(name);
            std::string tmp_name2(name2);
            // 新的结点
            if (mp.find(tmp_name1) == mp.end())
                mp[tmp_name1] = ++cnt;
            if (mp.find(tmp_name2) == mp.end())
                mp[tmp_name2] = ++cnt;
            int son_ = mp[tmp_name1];
            int fa_ = mp[tmp_name2];
            sons[fa_].push_back(son_);
        }

        if (dfs(root, 0) > dfs(root, 1)) {
            printf("%d %s\n", dfs(root, 0), unique[root][0] == true ? "Yes": "No");
        } else if (dfs(root, 1) > dfs(root, 0)){
            printf("%d %s\n", dfs(root, 1), unique[root][1] == true ? "Yes": "No");
        } else {
            printf("%d %s\n", dfs(root, 1), "No");
        }
    }
    return 0;
}
