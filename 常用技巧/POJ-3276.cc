/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-02-08 16:56:02 PM
 * File Name     : POJ-3276.cc
 */

//#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <string>

void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int INF = 1e9;
const int MAXN = 5e3 + 5;
int N;
char A[MAXN];
int dependency[MAXN], dependency_copy[MAXN];

bool valid() {
  for (int i = 1; i <= N; ++i) 
    if (dependency_copy[i])
      return false;
  return true;
}
int main() {
  std::cin >> N;
  for (int i = 1; i <= N; ++i) 
    std::cin >> A[i];
  // 处理依赖关系, 和前面的相同为0, 不同为1
  char pre = 'F';
  for (int i = 1; i <= N; ++i) {
    if (A[i] == pre) dependency[i] = 0, pre = A[i];
    else dependency[i] = 1, pre = A[i];
  }
  int ans_M = INF, ans_K;
  // 枚举k, 即反转区间的长度
  for (int k = 1; k <= N; ++k) {
    std::memcpy(dependency_copy, dependency, sizeof dependency);
    int op = 0;
    for (int i = 1; i <= N && i + k <= N + 1; ++i) {
      if (dependency_copy[i]) {
        ++op;
        dependency_copy[i] ^= 1;
        dependency_copy[i + k] ^= 1;
      }
    }
    if (valid()) {
      if (op < ans_M) ans_M = op, ans_K = k;
    }
  }
  std::cout << ans_K << " " << ans_M;
  return 0;
}
