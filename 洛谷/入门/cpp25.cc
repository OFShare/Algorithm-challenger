/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-06-14 17:25:16 PM
 * File Name     : cpp25.cc
 */

#include <bits/stdc++.h>

// a non-optimized way of checking for prime numbers:
bool do_check_prime(int x) {
  for (int i = 2; i < x; ++i) {
    if (x % i == 0)
      return false;
  }
  return true;
}

int main() {
  // call function asynchronously:
  // std::future < bool > fut = std::async(do_check_prime, 194232491);
  std::future < bool > fut = std::async(std::launch::async, do_check_prime, 194232491);

  std::cout << "Checking, please wait" << std::endl;
  // 设置超时间隔.
  std::chrono::milliseconds span(10); 

  while (1) {
    if (fut.wait_for(span) == std::future_status::timeout) {
      std::cout << "timeout" << std::endl;
    } else if (fut.wait_for(span) == std::future_status::ready) {
      std::cout << "ready" << std::endl;
      break;
    } else if (fut.wait_for(span) == std::future_status::deferred) {
      std::cout << "deferred" << std::endl;
    }
  }

  // guaranteed to be ready (and not block) after wait returns
  if (fut.get())
    std::cout << "is prime.\n";
  else
    std::cout << "is not prime.\n";
  return 0;
}
