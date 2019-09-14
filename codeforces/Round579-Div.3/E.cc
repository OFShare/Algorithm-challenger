//
// Created by OFShare on 2019-09-14
//

#include <bits/stdc++.h>

const int maxn = 2e5 + 5;
int n;
int A[maxn];
std::set<int> st;

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &A[i]);
    }
    std::sort(A + 1, A + 1 + n);
    for(int i = 1; i <= n; ++i) {
        if(i == 1) {
            st.insert(std::max(1, A[i] - 1));
        } else {
            if(!st.count(A[i] - 1) && A[i] - 1 >= 1) {
                st.insert(A[i] - 1);
            } else if(!(st.count(A[i])) && A[i] >= 1) {
                st.insert(A[i]);
            } else if(!(st.count(A[i] + 1)) && A[i] + 1 >= 1) {
                st.insert(A[i] + 1);
            }
        }
    }
    printf("%d", (int)st.size());
    return 0;
}

