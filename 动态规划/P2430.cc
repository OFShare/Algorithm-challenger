//
// created by OFShare on 2019-08-10
//

#include <bits/stdc++.h>

const int maxn = 5e3 + 10;
int wky,wang;
int m,n,T;
int t[maxn];
int dp[maxn][maxn];

struct node{
    int id;
    int value;
}A[maxn];

int main(){
    scanf("%d %d %d %d",&wky, &wang, &m, &n);
    for(int i=1;i<=n;++i){
        int tmp;
        scanf("%d",&tmp);
        t[i] = tmp * (wang/wky);
    }
    for(int i=1;i<=m;++i){
        scanf("%d %d",&A[i].id, &A[i].value);
    }
    scanf("%d",&T);
    for(int i=1;i<=m;++i){
        for(int j=0;j<=T;++j){
            dp[i][j] = std::max(dp[i][j], dp[i-1][j]);
            if(j-t[A[i].id]>=0)
                dp[i][j] = std::max(dp[i][j], dp[i-1][j-t[A[i].id] ] + A[i].value);
        }
    }
    printf("%d",dp[m][T]);
    return 0;
}
