/*
 * Created by OFShare 2019-10-31
 *
 */

#include <bits/stdc++.h>

const int maxn = 10 + 5;
int t;
int A[maxn];
bool ok;
std::vector<int> stk1, stk2;

// 从1~point的球都已经落下的情况, 即前面每个球落在哪里已经确定了
void dfs(int point) {
    // 递归的边界
    if (point == 11) {
        // 判断两管的球是否都满足
        bool is_ok = true;
        for (int i = 0; i < (int)stk1.size() - 1; ++i) {
            if (stk1[i] > stk1[i + 1])
                is_ok = false;
        }
        for (int i = 0; i < (int)stk2.size() - 1; ++i) {
            if (stk2[i] > stk2[i + 1])
                is_ok = false;
        }
        if (is_ok)
            ok = is_ok;
        return ;
    }
    int ball = A[point];
    for (int i = 1; i <= 2; ++i) {
        // 放进左边
        if (i == 1) {
            stk1.push_back(ball);
            dfs(point + 1);
            // 回溯, 把放进去的弹出来
            stk1.pop_back();
        }
        // 放进右边
        if (i == 2) {
            stk2.push_back(ball);
            dfs(point + 1);
            stk2.pop_back();
        }
    }
}
int main() {
#ifdef Acui
    freopen("datain.txt", "r", stdin);
    freopen("dataoutmy.txt", "w", stdout);
#endif
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) {
        // 初始化
        stk1.clear();
        stk2.clear();
        ok = false;

        for (int k = 1; k <= 10; ++k)
            scanf("%d", &A[k]);
        dfs(1);
        if (ok)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
