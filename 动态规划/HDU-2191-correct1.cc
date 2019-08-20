//
// created by OFShare on 2019-08-18
//

// 这是正确的写法1，使用朴素的二维dp[i][j]
// 我们用个变量currentStage表示现在更新到第几层即可
// 这样在拆分后，转成01背包时，zeroPack传进去正确的层(currentStage)就可以了
// 有个地方需要注意，原来可能只有100层(即100种物品)，拆分后currentStage肯定不止100层，应该适当扩大点

//#include <bits/stdc++.h>
#include <cstdio>
#include <cmath>
#include <cmath>
#include <iostream>

const int maxn = 2e3+5;
const int INF = 1e9;
int t,n,m,currentStage;
int dp[maxn][maxn/10];

void zeroPack(int i, int cost, int weight){
    for(int j=0;j<=n;++j){
        // 不选
        dp[i][j] = dp[i-1][j];
        // 选
        if(j-cost>=0)
            dp[i][j] = std::max(dp[i][j], dp[i-1][j-cost] + weight);
    }
}
void completePack(int i, int cost, int weight){
    for(int j=0;j<=n;++j){
        // 不选
        dp[i][j] = dp[i-1][j];
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
        std::fill(dp[0], dp[0] + maxn -2, 0);
        currentStage = 0;

        for(int i=1;i<=m;++i){
            int cost,weight,number;
            scanf("%d %d %d",&cost,&weight,&number);
            // 完全背包
            if(cost*number > n)
                completePack(++currentStage, cost, weight);
            // 拆分物品，转换为01背包
            else{
                int k = 1;
                while(k<number){
                    zeroPack(++currentStage, k*cost, k*weight);
                    number -= k;
                    k<<=1;
                }
                zeroPack(++currentStage, number*cost, number*weight);
            }
        }
        printf("%d\n",dp[currentStage][n]);
    }
    return 0;
}
