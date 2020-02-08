/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-02-08 16:42:35 PM
 * File Name     : POJ-3320.cc
 */

//#include <bits/stdc++.h>
#include <cstdio>
#include <set>
#include <map>
#include <cstring>

void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int INF = 1e9;
const int N = 1e6 + 6;
int P, A[N];
std::set<int> st;
std::map<int, int> mp;

int main() {
  scanf("%d", &P);
  for (int i = 1; i <= P; ++i) 
    scanf("%d", &A[i]), st.insert(A[i]);
  
  int ans = INF, needed = st.size();
  // 滑动窗口是用map来维护的
  int L = 1, R = 1;
  mp.insert({A[L], 1});
  while (L <= R && L <= P && R <= P) {
    if (mp.size() == needed) {
      ans = std::min(ans, R - L + 1); 
      mp[A[L]]--;
      if (mp[A[L]] == 0) mp.erase(A[L]);
      ++L;
    } else {
      ++R;
      mp[A[R]]++;
    }
  }
  printf("%d\n", ans);
  return 0;
}
