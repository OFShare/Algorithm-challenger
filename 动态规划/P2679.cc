//
// created by OFShare on 2019-09-01
//

#include <bits/stdc++.h>

const int mod = 1e9 + 7;
const int maxn = 1e3 + 5;
int n,m,k_;
char A[maxn], B[maxn];
// dp[i][j][k][0]: 字符串A的前i个元素，选出k个不重叠子串，不选A的第i个字符，匹配了前j个字符串B，的方案数
// dp[i][j][k][1]: 字符串A的前i个元素，选出k个不重叠子串，选A的第i个字符，匹配了前j个字符串B，的方案数
int dp[2][200+1][200+1][2];

int main(){
    scanf("%d %d %d", &n, &m, &k_);
    scanf("%s %s", A+1, B+1);
    // 初始化
    dp[0][0][0][0] = 1;

    for(int i=1; i<=n; ++i){
        for(int j=0; j<=std::min(i, m); ++j){
            for(int k=0; k<=std::min(j, k_); ++k){
                // 不选第i个元素
                dp[i&1][j][k][0] = 0;
                dp[i&1][j][k][0] = (dp[i&1][j][k][0] + dp[(i-1)&1][j][k][0]) % mod;
                dp[i&1][j][k][0] = (dp[i&1][j][k][0] + dp[(i-1)&1][j][k][1]) % mod;

                // 选第i个元素,单独构成一组或者和前面的组合成一组,当然只匹配了字符串B的前j-1个
                dp[i&1][j][k][1] = 0;
                if(j-1 >= 0 && k-1 >= 0 && B[j] == A[i])
                    dp[i&1][j][k][1] = (dp[i&1][j][k][1] + dp[(i-1)&1][j-1][k-1][0]) % mod;
                if(j-1 >= 0 && k-1 >= 0 && B[j] == A[i])
                    dp[i&1][j][k][1] = (dp[i&1][j][k][1] + dp[(i-1)&1][j-1][k-1][1]) % mod;
                if(j-1 >= 0 && B[j] == A[i])
                    dp[i&1][j][k][1] = (dp[i&1][j][k][1] + dp[(i-1)&1][j-1][k][1]) % mod;

            }
        }
    }
    printf("%d\n", (dp[n&1][m][k_][0] + dp[n&1][m][k_][1]) % mod);
    return 0;
}
