//
// created by OFShare on 2019-08-18
//

//#include <bits/stdc++.h>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cassert>

const int maxn = 2e5+10;
const int INF = 1e9;
int cnt_i[7];
int dp[3][maxn];

int main(){
#ifdef OFShare
    std::freopen("datain.txt", "r", stdin);
    std::freopen("dataout.txt", "w", stdout);
#endif
    int kase = 0;
    while(scanf("%d %d %d %d %d %d",&cnt_i[1],&cnt_i[2],&cnt_i[3],&cnt_i[4],&cnt_i[5],&cnt_i[6])){
        int sum_ = 0;
        std::vector<int> number_splited[7];
        for(int i=1;i<=6;++i){
            sum_ += cnt_i[i] * i;
        }
        if(sum_ == 0) break;

        // 对每一种物品拆分
        for(int i=1;i<=6;++i){
            int bit = 1;
            int left_ = cnt_i[i];
            for(bit=1;bit<=left_;bit<<=1){
                number_splited[i].push_back(bit);
                left_ -= bit;
            }
            number_splited[i].push_back(left_);
            // 检查"拆分"是否正确
            int sum = 0;
            for(int k=0;k<number_splited[i].size();++k){
                sum += number_splited[i][k];
            }
            assert(sum==cnt_i[i]);
        }
        // 奇数和显然不能平分
        if(sum_&1){
            printf("Collection #%d:\n",++kase);
            printf("Can't be divided.\n");
            printf("\n");
            continue;
        }
        // 初始化
        sum_ /=2 ;
        for(int i=0;i<3;++i){
            for(int j=0;j<maxn-5;++j){
                dp[i][j] = -INF;
            }
        }
        dp[0][0] = 0;

        int currentStage = 0;
        for(int i=1;i<=6;++i){
            // 第i种物品每个"拆分后"的物品,都要更新整个背包容量
            for(int k=0;k<number_splited[i].size();++k){
                ++currentStage;
                for(int j=0;j<=sum_;++j){
                    // 不选
                    dp[currentStage&1][j] = std::max(dp[currentStage&1][j], dp[(currentStage-1)&1][j]);
                    // 选
                    if(j-i*number_splited[i][k] >= 0)
                        dp[currentStage&1][j] = std::max(dp[currentStage&1][j], dp[(currentStage-1)&1][j-i*number_splited[i][k]] + i*number_splited[i][k]);
                }
            }
        }
        if(dp[currentStage&1][sum_] == sum_){
            printf("Collection #%d:\n",++kase);
            printf("Can be divided.\n");
        }else{
            printf("Collection #%d:\n",++kase);
            printf("Can't be divided.\n");
        }
        printf("\n");
    }
    return 0;
}
