//
// Created by OFShare on 2019-09-10
//

#include <bits/stdc++.h>
long long q, n, m;
std::vector<long long > vec;

int main() {
    scanf("%lld", &q);
    while(q--) {
        scanf("%lld %lld", &n, &m);
        vec.clear();
        // 记录一个循环节的和
        long long sum = 0;
        for(int i = 1; i <= 10; ++i) {
            vec.push_back(m*i%10);
            sum += m*i%10;
        }

        // 几个完整的循环节的和
        long long ans = n / m / 10 * sum;
        // 余下的一个循环节里剩下的元素求和
        for(int i = 0; i < n / m % 10; ++i) {
            ans += vec[i];
        }
        printf("%lld\n", ans);
    }
    return 0;
}
