//
// Created by OFShare on 2019-09-11
//

#include <bits/stdc++.h>

const int maxn = 2e5 + 5;
int n, k;
// vec[i]记录的是对应数变成i时，对应的操作数
std::vector<int> vec[maxn];

void preprocess(int x) {
    int cnt = 0;
    while(x) {
        vec[x].push_back(cnt);
        x /= 2;
        cnt++;
    }
    vec[0].push_back(cnt);
}

int main() {
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; ++i) {
        int x;
        scanf("%d", &x);
        preprocess(x);
    }
    int ans = 1e9;
    // 枚举每个可能k个相等的数
    for(int i = 0; i <= 2e5; ++i) {
        if(vec[i].size() < k) continue;
        std::sort(vec[i].begin(), vec[i].end());
        ans = std::min(ans, std::accumulate(vec[i].begin(), vec[i].begin() + k, 0));
    }
    printf("%d", ans);
    return 0;
}
