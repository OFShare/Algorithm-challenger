/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-06-14 17:07:23 PM
 * File Name     : cpp24.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
#ifdef Acui
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
}

// a non-optimized way of checking for prime numbers:
bool is_prime(ll x) {
  for (ll i = 2; i < x; ++i)
    if (x % i == 0)
      return false;
  return true;
}

int main() {
  // call function asynchronously:
  std::future < bool > fut = std::async(is_prime, 444444443LL);
 
  std::cout << "go on" << std::endl;
  // do something while waiting for function to set future:
  std::cout << "checking, please wait" << std::endl;

  bool x = fut.get();         // retrieve return value

  std::cout << "\n444444443 " << (x ? "is" : "is not") << " prime.\n";

  return 0;
}
