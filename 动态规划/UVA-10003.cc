//
// created by OFShare on 2019-09-01
//

#include <bits/stdc++.h>

const int INF = 1e5;
const int maxn = 50 + 5;
int L,n;
int A[maxn];
// dp[i][j]: i到j这个区间最少的费用
int dp[maxn][maxn];

int dfs(int start_, int end_){
    if(dp[start_][end_] != -1) return dp[start_][end_];
    // 递归边界, 两个端点不能切
    if(end_ - start_ ==1)
        return dp[start_][end_] = 0;
    int ans = INF;
    for(int k=start_+1; k<end_; ++k){
        ans = std::min(ans, dfs(start_, k) + dfs(k, end_) + (A[end_] - A[start_]));
    }
    return dp[start_][end_] = ans;
}

int main(){
    while(scanf("%d", &L) && L){
        scanf("%d", &n);
        // 初始化
        A[0] = 0;
        A[n+1] = L;
        std::memset(dp, -1, sizeof dp);

        for(int i=1; i<=n; ++i){
            scanf("%d", &A[i]);
        }
        printf("The minimum cutting is %d.\n", dfs(0, n+1));
    }
    return 0;
}
