/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-06-20 22:20:52 PM
 * File Name     : cpp30.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

typedef enum memory2 {
  memory_order_relaxed,
  memory_order_consume,
  memory_order_acquire,
  memory_order_release,
  memory_order_acq_rel,
  memory_order_seq_cst
} memory1, memory_order;

int main() {
  memory_order m1;
  std::cout << m1 << std::endl;

  memory_order m2 = memory_order::memory_order_seq_cst;
  std::cout << m2 << std::endl;

  memory1 a;
  memory2 b;
  memory_order c;
  return 0;
}
