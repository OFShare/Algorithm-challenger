//
// created by OFShare on 2019-08-09
//

// 构造的一组输入数据2 6 10 -10 -10 100 -20 10
// HDU-1024
// 题意：给n个数，将其分为m部分，各部分之间不能有交叉重叠，求最大和

#include <bits/stdc++.h>

const int maxn = 1e6+10;
const int INF = 1e9;
int n,m;
// 定义dp[i][j][0]: 前i个元素构成j组，且最后一组不以第i个元素结尾
// 定义dp[i][j][1]: 前i个元素构成j组，且最后一组以第i个元素结尾
int dp[3][maxn][3];

int main(){
    while(scanf("%d %d",&m,&n)!=EOF){
        // 初始化
        for(int i=0;i<=n;++i){
            for(int j=0;j<=m;++j){
                for(int k=0;k<2;++k){
                    dp[i&1][j][k] = -INF;
                    dp[0][0][1] = -INF;
                    dp[0][0][0] = 0;
                }
            }
        }
        for(int i=1;i<=n;++i){
            int tmp;
            scanf("%d",&tmp);
            for(int j=0;j<=m;++j){
                // 不选，不以第i个元素结尾，显然前i-1个已经构成了j组
                dp[i&1][j][0] = std::max(dp[(i-1)&1][j][0], dp[(i-1)&1][j][1]);
                // 选，即以第i个元素结尾，显然要么加入前面，要么自己单独构成一组
                // 重新初始化,因为滚动几次后,dp数组里存的是前两次的状态,当前状态需要重新初始化
                dp[i&1][j][1] = -INF;
                dp[i&1][j][1] = std::max(dp[i&1][j][1], dp[(i-1)&1][j][1] + tmp);
                if(j-1>=0){
                    dp[i&1][j][1] = std::max(dp[i&1][j][1], dp[(i-1)&1][j-1][0] + tmp);
                    dp[i&1][j][1] = std::max(dp[i&1][j][1], dp[(i-1)&1][j-1][1] + tmp);
                }
            }
        }
        printf("%d\n",std::max(dp[n&1][m][0], dp[n&1][m][1]));
        //printf("\ndebug\n");
        //printf("%d %d %d %d %d", dp[5&1][1][0], dp[5&1][1][1], dp[4&1][1][1], dp[4&1][1][0], dp[1&1][1][0]);
    }
    return 0;
}
