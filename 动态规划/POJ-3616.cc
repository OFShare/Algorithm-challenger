//
// created by OFShare on 2019-08-01
//

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

const int maxn = 1e3 + 10;
int n,m,rest;
int dp[maxn];

struct node{
    int s_,e_,efficiency;
    bool operator<(const node &rhs) const {
        return e_ < rhs.e_;
    }
}A[maxn];

int main(){
    scanf("%d %d %d",&n,&m,&rest);
    for(int i=1;i<=m;++i){
        scanf("%d %d %d",&A[i].s_,&A[i].e_,&A[i].efficiency);
    }
    // 按结束时间从小到大排序
    std::sort(A+1,A+1+m);

    for(int i=1;i<=m;++i){
        dp[i] = A[i].efficiency;
        for(int j=1;j<=i-1;++j){
            // 状态j的结束时间 + 休息时间要<= 状态i的开始时间
            if(A[j].e_ + rest <= A[i].s_)
                dp[i] = std::max(dp[i], dp[j]+A[i].efficiency);
        }
    }
    int ans = *std::max_element(dp+1,dp+1+m);
    printf("%d",ans);
    return 0;
}
