//
// Created by OFShare on 2019-10-14
//

#include <bits/stdc++.h>

const int maxn = 1e5 + 5;
int n, T;
// sons[i]: 记录结点i的孩子结点都有谁
std::vector<int> sons[maxn];

// 以结点src作为根的子树, 结点src向上发起请愿书最少需要多个工人
int dfs(int src) {
    // 递归的边界
    if (sons[src].size() == 0)
        return 1;
    std::vector<int> vec;
    for (int i = 0; i < sons[src].size(); ++i) {
        int child = sons[src][i];
        vec.push_back(dfs(child));
    }
    std::sort(vec.begin(), vec.end());
    // 至少需要count个下属
    int count = std::ceil(sons[src].size() * T * 0.01);
    int sum = 0;
    for (int i = 0; i < count; ++i) {
        sum += vec[i];
    }
    return sum;
}

int main() {
    while (scanf("%d %d", &n, &T) && (n + T)) {
        // 多组数据, 清空
        for (int i = 0; i <=n; ++i) {
            sons[i].clear();
        }
        for (int i = 1; i <= n; ++i) {
            int tmp;
            scanf("%d", &tmp);
            sons[tmp].push_back(i);
        }
        printf("%d\n", dfs(0));
    }
    return 0;
}
