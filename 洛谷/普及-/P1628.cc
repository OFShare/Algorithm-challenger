/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-03-17 20:27:17 PM
 * File Name     : P1628.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

int n;
std::vector<std::string> vec;

int main() {
  std::cin >> n;
  for (int i = 1; i <= n; ++i) {
    std::string str;
    std::cin >> str;
    vec.push_back(str);
  }
  std::sort(vec.begin(), vec.end());

  std::string target;
  std::cin >> target;
  for (int i = 0; i < vec.size(); ++i) {
    if (vec[i].find(target, 0) == 0) 
      std::cout << vec[i] << std::endl;
  }
  return 0;
}
