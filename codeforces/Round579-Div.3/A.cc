//
// Created by OFShare on 2019-09-14
//

#include <bits/stdc++.h>

const int maxn = 2e2 + 5;
int q, n;
int A[maxn];

int main() {
    scanf("%d", &q);
    while(q--) {
        scanf("%d", &n);
        for(int i = 0; i < n; ++i) {
            scanf("%d", &A[i]);
            --A[i];
        }
        bool is_ok1 = true, is_ok2 = true;
        for(int i = 0; i < n; ++i) {
            int next_index = (i + 1) % n;
            // clockwise, 升序
            if((A[i] + 1) % n != A[next_index]) is_ok1 = false;
            // counterclockwise, 降序
            if((A[next_index] + 1) % n != A[i]) is_ok2 = false;
        }
        if(is_ok1 || is_ok2)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
