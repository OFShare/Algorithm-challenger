//
// created by OFShare on 2019-08-17
//

#include <bits/stdc++.h>

const int maxn = 1e3 + 10;
int n;
// 按额定电压排序后,dp[i]:表示前i个物品,以第i个物品结尾的最小费用
// 因为前i个物品中,排序后第i个物品的额定电压最大，所以它是不能被其他物品替换的，所以第i个物品
// 一定是结尾，这里只是显示的定义出来。
int dp[maxn],sum_[maxn];

struct node{
    // 额定电压,电压源,费用,数量
    int voltage_rating;
    int voltage_source;
    int cost;
    int number;
    // 额定电压从小到大排序
    const bool operator< (const node& rhs) const{
        return voltage_rating < rhs.voltage_rating;
    }
}A[maxn];

int main(){
    while(scanf("%d",&n) && n){
        memset(sum_, 0, sizeof sum_);
        memset(dp, 0x3f3f3f, sizeof dp);
        dp[0] = 0;
        for(int i=1;i<=n;++i){
            scanf("%d %d %d %d",&A[i].voltage_rating, &A[i].voltage_source, &A[i].cost, &A[i].number);
        }

        // 排序以及前缀和
        std::sort(A+1,A+1+n);
        for(int i=1;i<=n;++i){
            sum_[i] = sum_[i-1] + A[i].number;
        }
        // dp过程
        for(int i=1;i<=n;++i){
            for(int j=0;j<i;++j){
                dp[i] = std::min(dp[i], dp[j] + (sum_[i]-sum_[j])*A[i].cost + A[i].voltage_source);
            }
        }
        printf("%d\n",dp[n]);
    }
    return 0;
}
