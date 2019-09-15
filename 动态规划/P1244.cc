//
// Created by OFShare on 2019-09-15
//

#include <bits/stdc++.h>

int h, k;

int main() {
    scanf("%d %d", &h, &k);
    long long ans = k + 1;
    for(int i = 1; i <= h; ++i) {
        ans = ans * 2;
    }
    printf("%lld\n", ans);
    return 0;
}
