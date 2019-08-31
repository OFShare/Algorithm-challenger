//
// created by OFShare on 2019-08-31
//

#include <bits/stdc++.h>

const int INF = 1e5;
const int maxn = 1e3 + 5;
int n;
char A[maxn];
// dp[i][j]：i到j这个区间，最少的回文串组数
// 因为多了一个枚举点k，所以时间复杂度是O(n^3)，当然会超时
int dp[maxn][maxn];

int is_palindrome(int start_, int end_){
    if((start_ > end_) || (start_ == end_))
        return 1;
    if(A[start_] == A[end_])
        return is_palindrome(start_+1, end_-1);
    return INF;
}

int dfs(int start_, int end_){
    if(dp[start_][end_] != -1)
        return dp[start_][end_];
    // 递归边界
    if(start_ == end_)
        return dp[start_][end_] = 1;
    // 考虑整个串
    int ans = is_palindrome(start_, end_);
    if(ans == 1)
        return dp[start_][end_] = ans;
    for(int k=start_; k<end_; ++k){
        ans = std::min(ans, dfs(start_, k) + dfs(k+1, end_));
    }
    return dp[start_][end_] = ans;
}

int main(){
    scanf("%d", &n);
    while(n--){
        scanf("%s", A+1);
        std::memset(dp, -1, sizeof dp);
        printf("%d\n", dfs(1, strlen(A+1)));
    }
    return 0;
}
