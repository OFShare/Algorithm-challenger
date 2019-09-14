//
// Created by OFShare on 2019-09-14
//

#include <bits/stdc++.h>

const int maxn = 2e5 + 5;
char S[maxn], T[maxn];
// prefix[i]记录T[i]这个字符，从左往右第一次出现的位置
// suffix[i]记录T[i]这个字符，从右往左第一次出现的位置
int prefix[maxn], suffix[maxn];

int main() {
    scanf("%s %s", S+1, T+1);
    int pos = 1;
    // 从左往右
    for(int i = 1; i <= strlen(S+1); ++i) {
        if(S[i] == T[pos])
            prefix[pos] = i, ++pos;
    }
    pos = strlen(T+1);
    // 从右往左
    for(int i = strlen(S+1); i >= 1; --i) {
        if(S[i] == T[pos])
            suffix[pos] = i, --pos;
    }
    int ans = 0;
    for(int i = 1; i <= strlen(T+1)+1; ++i) {
        if(i == 1) {
            ans = std::max(ans, (int)suffix[i] - 1);
            continue;
        }
        if(i == strlen(T + 1) + 1) {
            ans = std::max(ans, (int)strlen(S + 1) - prefix[i - 1]);
            continue;
        }
        ans = std::max(ans, suffix[i] - prefix[i-1] - 1);
    }
    printf("%d\n", ans);
    return 0;
}
