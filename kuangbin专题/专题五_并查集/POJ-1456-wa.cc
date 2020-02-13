/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-02-12 00:39:32 AM
 * File Name     : POJ-1456.cc
 */

//#include <bits/stdc++.h>
#include <cstdio>
#include <vector>
#include <set>

void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 1e4 + 5;
int n;
int main() {
  while (scanf("%d", &n) != EOF) {
    std::vector<int> A[N];
    std::set<int> st;
    for (int i = 1; i <= n; ++i) {
      int p, d;
      scanf("%d %d", &p, &d);
      if (A[d].size() == 0) 
        A[d].push_back(p);
      else 
        if (A[d][0] < p)
          A[d][0] = p;
      st.insert(d);
    }
    int ans = 0;
    for (std::set<int>::iterator ite = st.begin(); ite != st.end(); ++ite) {
      int index = *ite;
      ans += A[index][0]; 
    }
    printf("%d\n", ans);
  }
  return 0;
}
