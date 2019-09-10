//
// Created by OFShare on 2019-09-08
//

#include <bits/stdc++.h>

const int maxn = 2e5 + 5;
int t,n;
int A[maxn];

int main() {
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i){
            scanf("%d", &A[i]);
        }
        int ans = 0;
        int minV = 1e9;
        for(int i = n; i >= 1; --i){
            if(A[i] > minV)
                ++ans;
            minV = std::min(minV, A[i]);
        }
        printf("%d\n", ans);
    }
    return 0;
}
