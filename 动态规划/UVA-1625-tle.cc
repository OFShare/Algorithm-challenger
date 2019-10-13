//
// Created by OFShare on 2019-10-08
//

#include <bits/stdc++.h>

const int maxn = 5e3 + 5;
const int INF = 1e9;
int t;
char A[maxn], B[maxn];
// dp[i][j]: 表示前i个字符串A, 和前j个字符串B合并后对答案的最小贡献
int dp[maxn][maxn];

// 记录输入的字符串A, 和B
struct node {
    int start_ = INF;
    int end_ = -INF;
}character1[26], character2[26];

void init() {
    // 初始化
    for (int i = 0; i < 26; ++i) {
        character1[i].start_ = INF;
        character1[i].end_ = -INF;
        character2[i].start_ = INF;
        character2[i].end_ = -INF;
    }
}

int calc(int i, int j) {
    int number = 0;
    // 枚举每种字符在字符串A和字符串是否开始但是没有结束
    for (int k = 0; k < 26; ++k) {
        if (character1[k].start_ >= INF && character2[k].start_ >= INF)
            continue;
        if ((character1[k].start_ <= i || character2[k].start_ <= j ) && (character1[k].end_ > i || character2[k].end_ > j))
            ++number;
    }
    return number;
}

int main() {
    scanf("%d", &t);
    while (t--) {
        init();
        scanf("%s %s", A + 1, B + 1);
        int n = strlen(A + 1);
        int m = strlen(B + 1);
        // 预处理, 记录每个字符第一次出现的位置和最后一次出现的位置
        for (int i = 1; i <= n; ++i) {
            character1[A[i] - 'A'].start_ = std::min(character1[A[i] - 'A'].start_, i);
            character1[A[i] - 'A'].end_ = std::max(character2[A[i] - 'A'].end_, i);
        }
        for (int i = 1; i <= m; ++i) {
            character2[B[i] - 'A'].start_ = std::min(character2[B[i] - 'A'].start_, i);
            character2[B[i] - 'A'].end_ = std::max(character2[B[i] - 'A'].end_, i);
        }
        // dp
        //std::memset(dp, 0x3f3f3f, sizeof dp);
        for (int i = 0; i < n + 1; ++i) {
            for (int j = 0; j < m + 1; ++j) {
                dp[i][j] = INF + 10;
            }
        }
        dp[0][0] = 0;
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                if (i - 1 >= 0)
                    dp[i][j] = std::min(dp[i][j], dp[i - 1][j] + calc(i, j));
                if (j - 1 >= 0)
                    dp[i][j] = std::min(dp[i][j], dp[i][j - 1] + calc(i, j));
            }
        }
        printf("%d\n", dp[n][m]);
    }
    return 0;
}
