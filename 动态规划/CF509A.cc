//
// created by OFShare on 2019-08-10
//

#include <bits/stdc++.h>

const int maxn = 10+5;
int n;
int A[maxn][maxn];

int main(){
    scanf("%d",&n);
    for(int k=1;k<=n;++k){
        A[k][1] = 1;
        A[1][k] = 1;
    }
    for(int i=2;i<=n;++i){
        for(int j=2;j<=n;++j){
            A[i][j] = A[i-1][j] + A[i][j-1];
        }
    }
    int ans = 0;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            ans = std::max(ans, A[i][j]);
        }
    }
    printf("%d\n",ans);
    return 0;
}
