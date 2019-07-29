//
// created by OFShare on 2019-07-26
//

#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const int maxn = 12880+10;
int n,m;
// 滚动数组
int dp[2][maxn];

int main(){
    scanf("%d %d",&n,&m);
    dp[0][0]=0;
    for(int i=0;i<=n-1;++i){
        int w,d;
        scanf("%d %d",&w,&d);
        for(int j=0;j<=m;++j){
            // 不选
            dp[(i+1)&1][j]=std::max(dp[(i+1)&1][j],dp[(i)&1][j]);
            // 选
            if(j+w<=m)
                dp[(i+1)&1][j+w]=std::max(dp[(i+1)&1][j+w],dp[(i)&1][j]+d);
        }
    }
    printf("%d",dp[n&1][m]);
    return 0;
}
