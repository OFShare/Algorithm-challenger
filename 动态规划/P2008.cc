//
// created by OFShare on 2019-08-24
//

// https://www.luogu.org/problem/P2008
#include <bits/stdc++.h>

const int maxn = 1e4 + 5;
int n, A[maxn];
// dp[i]：前i个元素，以第i个元素结尾的最长不下降长度
int dp[maxn];
// sum[i]：dp[i]取最优时对应下的和
int sum[maxn];

int main(){
    scanf("%d", &n);
    for(int i=1;i<=n;++i){
        scanf("%d", &A[i]);
    }
    for(int i=1;i<=n;++i){
        // 至少为1，即它本身
        dp[i] = 1;
        sum[i] = A[i];

        for(int j=1;j<i;++j){
            if(A[j] <= A[i])
                dp[i] = std::max(dp[i], dp[j] + 1);
        }

        for(int j=1;j<i;++j){
            if(A[j] <= A[i] && dp[j] + 1 == dp[i]){
                sum[i] = sum[j] + A[i];
                break;
            }
        }

        printf("%d ", sum[i]);
    }
    return 0;
}
