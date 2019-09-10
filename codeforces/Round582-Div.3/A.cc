//
// Created by OFShare on 2019-09-08
//

#include <bits/stdc++.h>

const int maxn = 1e2 + 5;
int n;
int A[maxn];
int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; ++i){
        scanf("%d", &A[i]);
    }
    // 枚举最后都移动到相同的点
    int ans = 1e9;
    for(int i=1; i<=n; ++i){
        int sum = 0;
        for(int j=1; j<=n; ++j){
            sum += std::abs(A[j]-A[i])%2;
        }
        ans = std::min(ans, sum);
    }
    printf("%d\n", ans);
    return 0;
}
