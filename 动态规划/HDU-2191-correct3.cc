//
// created by OFShare on 2019-08-20
//

// 这是正确的写法3，将二维dp[i][j]压缩为一维dp[j]优化内存占用
//#include <bits/stdc++.h>
#include <cstdio>
#include <cmath>
#include <cmath>
#include <iostream>

const int maxn = 2e2+5;
const int INF = 1e9;
int t,n,m,currentStage;
int dp[maxn];

void zeroPack(int cost, int weight){
    for(int j=n;j>=0;--j){
        // 不选
        dp[j] = std::max(dp[j], dp[j]);
        // 选
        if(j-cost>=0)
            dp[j] = std::max(dp[j], dp[j-cost] + weight);
    }
}
void completePack(int cost, int weight){
    for(int j=0;j<=n;++j){
        // 不选
        dp[j] = std::max(dp[j], dp[j]);
        // 选
        if(j-cost>=0)
            dp[j] = std::max(dp[j], dp[j-cost] + weight);
    }
}

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        // 初始化
        std::fill(dp, dp + maxn -2, 0);
        currentStage = 0;

        for(int i=1;i<=m;++i){
            int cost,weight,number;
            scanf("%d %d %d",&cost,&weight,&number);
            // 完全背包
            if(cost*number > n)
                completePack(cost, weight);
            // 拆分物品，转换为01背包
            else{
                int k = 1;
                while(k<number){
                    zeroPack(k*cost, k*weight);
                    number -= k;
                    k<<=1;
                }
                zeroPack(number*cost, number*weight);
            }
        }
        printf("%d\n",dp[n]);
        //for(int i=0;i<=currentStage;++i){
            //for(int j=0;j<=n;++j){
                //printf("%d ", dp[i][j]);
            //}
            //printf("\n");
        //}
    }
    return 0;
}
