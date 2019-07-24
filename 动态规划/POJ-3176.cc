//
// created by OFShare at 2019-07-24
//

//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>

using namespace std;

const int maxn=350+10;
int n;
int A[maxn][maxn],sum[maxn][maxn];

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=i;++j){
            scanf("%d",&A[i][j]);
        }
    }
    sum[1][1]=A[1][1];
    for(int i=1;i<=n-1;++i){
        for(int j=1;j<=i;++j){
        sum[i+1][j]=std::max(sum[i+1][j],sum[i][j]+A[i+1][j]);
        sum[i+1][j+1]=std::max(sum[i+1][j+1],sum[i][j]+A[i+1][j+1]);
        }
    }
    int mx_value=0;
    for(int j=1;j<=n;++j){
        mx_value=std::max(mx_value,sum[n][j]);
    }
    printf("%d",mx_value);
    return 0;
}
