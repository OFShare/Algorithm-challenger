//
// Created by OFShare on 2019-09-14
//

#include <bits/stdc++.h>

int n;

int main() {
    scanf("%d", &n);
    long long max_common_divisor;
    // 求出n个数的最大公约数
    for(int i = 1; i <= n; ++i) {
        long long tmp;
        scanf("%lld", &tmp);
        if(i == 1)
            max_common_divisor = tmp;
        else
            max_common_divisor = std::__gcd(max_common_divisor, tmp);
    }

    int ans = 0;
    for(int i = 1; i <= std::sqrt(max_common_divisor); ++i) {
        if(max_common_divisor % i == 0){
            long long divisor = max_common_divisor / i;
            if(divisor * divisor == max_common_divisor)
                ++ans;
            else
                ans += 2;
        }
    }
    printf("%d", ans);
    return 0;
}

