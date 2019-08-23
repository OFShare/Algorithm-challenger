//
// created by OFShare on 2019-08-23
//

#include <bits/stdc++.h>

const int maxn = 1e3 + 5;
int n;
int A[maxn];
// dp[i][j]：前i个元素，能否组成j组
// 因为第i个元素肯定会被分进某一组，状态转移就是第i个元素单独一组，还是和前面的一组拼接起来
int dp[maxn][maxn];

int main(){
    scanf("%d", &n);
    for(int i=1;i<=n;++i){
        scanf("%d", &A[i]);
    }
    // 初始化
    dp[0][0] = 1;
    for(int i=1;i<=n;++i){
        for(int j=0;j<=i;++j){
            // 第i个元素单独组成一组
            if(A[i] >= 0)
                dp[i][j] |= dp[i-1][j];
            // 第i个元素和前面组成一组
            int sum = 0;
            for(int k=i;k>=1;--k){
                sum += A[k];
                if(sum>=0)
                    dp[i][j] |= dp[k-1][j-1];
                if(dp[i][j])
                    break;
            }
        }
    }
    for(int j=n;j>=1;--j){
        if(dp[n][j])
            printf("%d\n",j), exit(0);
    }
    printf("Impossible\n");
    return 0;
}
