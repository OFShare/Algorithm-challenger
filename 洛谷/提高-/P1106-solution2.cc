/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-06-06 17:12:21 PM
 * File Name     : P1106-solution2.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 250 + 5;
int n, k;
char A[N];

int main() {
  scanf("%s %d", A + 1, &k);
  n = std::strlen(A + 1);
  // 单调栈
  std::deque<char> que;
  for (int i = 1; i <= n; ++i) {
    while (!que.empty() && que.back() > A[i] && k) {
      k--;
      que.pop_back();
    }
    que.push_back(A[i]);
  }
  while (k) {
    que.pop_back();
    k--;
  }
  if (que.empty()) printf("0\n");
  else {
    bool zero = true, output = false;
    while (!que.empty()) {
      if (zero && que.front() == '0') {
        que.pop_front();
        continue;
      }
      zero = false, output = true;
      printf("%c", que.front());
      que.pop_front();
    }
    if (output == false) printf("0\n");
  }
  return 0;
}
