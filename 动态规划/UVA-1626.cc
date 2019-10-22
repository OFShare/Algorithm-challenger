//
// Created by OFShare on 2019-10-13
//

#include <bits/stdc++.h>

const int INF = 1e9;
const int maxn = 1e2 + 5;
int t;
char A[maxn];
// dp[i][j]: 表示i到j这个区间构成规则的序列最少需要添加的字符个数
int dp[maxn][maxn];

int dfs(int i, int j) {
    // 记忆化
    if (dp[i][j] != -1)
        return dp[i][j];
    // 递归的边界
    if (i > j)
        return dp[i][j] = 0;
    if (i == j)
        return dp[i][j] = 1;
    int ans = INF;
    if (A[i] == '(' && A[j] == ')' || (A[i] == '[' && A[j] == ']'))
        ans = std::min(ans, dfs(i + 1, j - 1));
    for (int k = i; k < j; ++k) {
        ans = std::min(ans, dfs(i, k) + dfs(k + 1, j));
    }
    return dp[i][j] = ans;
}

// 打印i~j这段区间构成的规则序列
void print(int i, int j) {
    // 递归的边界
    if (i > j)
        return ;
    if (i == j ) {
        if (A[i] == '(' || A[i] == ')')
            printf("()");
        else
            printf("[]");
        return ;
    }
    if ( (A[i] == '(' && A[j] == ')' || (A[i] == '[' && A[j] == ']') ) && dp[i][j] == dp[i + 1][j - 1]) {
        printf("%c", A[i]);
        print(i + 1, j - 1);
        printf("%c", A[j]);
        return ;
    }
    for (int k = i; k < j; ++k) {
        if (dp[i][j] == dp[i][k] + dp[k + 1][j]) {
            print(i, k);
            print(k + 1, j);
            return ;
        }
    }
}

void readline(char *src) {
    std::fgets(src, maxn - 2, stdin);
}

int main() {
#ifdef OFShare
    freopen("datain.txt", "r", stdin);
    freopen("dataout.txt", "w", stdout);
#endif
    char tmp[maxn];
    readline(tmp);
    std::sscanf(tmp, "%d", &t);
    while (t--) {
        std::memset(dp, -1, sizeof dp);
        // 读取空行
        readline(tmp);
        // 这里才是读取输入的一行字符串, 类似'xxxx\n\0', 所有用strlen 才需要 - 1, 不能将\n统计在内
        readline(A + 1);
        int len = strlen(A + 1) - 1;
        dfs(1, len);
        print(1, len);
        printf("\n");
        if(t) printf("\n");
    }
    return 0;
}
