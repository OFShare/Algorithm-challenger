//
// created by OFShare on 2019-08-18
//

// 这是错误的写法
// 错误的原因是，将物品拆分后跑01背包的时候,一直是第i种物品被更新，
// 如果第i种物品被拆分为3种，第一次是第i种物品被更新，接着应该是拆分出来的第i+1,i+2物品被更新，
// 而我们的zeroPack函数传进来的参数却一直是第i种物品，
// 所以这样写是错误的

#include <bits/stdc++.h>

const int maxn = 1e2+5;
const int INF = 1e9;
int t,n,m;
int dp[maxn][maxn];

void zeroPack(int i, int cost, int weight){
    for(int j=0;j<=n;++j){
        // 不选
        dp[i][j] = std::max(dp[i][j], dp[i-1][j]);
        // 选
        if(j-cost>=0)
            dp[i][j] = std::max(dp[i][j], dp[i-1][j-cost] + weight);
    }
}
void completePack(int i, int cost, int weight){
    for(int j=0;j<=n;++j){
        // 不选
        dp[i][j] = std::max(dp[i][j], dp[i-1][j]);
        // 选
        if(j-cost>=0)
            dp[i][j] = std::max(dp[i][j], dp[i][j-cost] + weight);
    }
}

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        // 初始化
        for(int i=0;i<maxn-2;++i)
            for(int j=0;j<maxn-2;++j)
                dp[i][j] = -INF;
        std::fill(dp[0], dp[0] + maxn -2, 0);

        for(int i=1;i<=m;++i){
            int cost,weight,number;
            scanf("%d %d %d",&cost,&weight,&number);
            // 完全背包
            if(cost*number > n)
                completePack(i, cost, weight);
            // 拆分物品，转换为01背包
            else{
                int k = 1;
                while(k<number){
                    zeroPack(i, k*cost, k*weight);
                    number -= k;
                    k<<=1;
                }
                zeroPack(i, number*cost, number*weight);
            }
        }
        printf("%d\n",dp[m][n]);
    }
    return 0;
}
