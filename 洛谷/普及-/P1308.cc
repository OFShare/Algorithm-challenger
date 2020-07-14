/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-03-15 22:07:05 PM
 * File Name     : P1308.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

std::string word;
std::vector<std::string> vec;

int main() {
  debug();
  std::cin >> word;
  std::string tmp;
  while (std::cin >> tmp) 
    vec.push_back(tmp);

  int first_position = -1, cnt = 0;
  for (int i = 0; i < vec.size(); ++i) {
    for (int j = 0; j < word.size(); ++j) word[j] = std::toupper(word[j]);
    for (int j = 0; j < vec[i].size(); ++j) vec[i][j] = std::toupper(vec[i][j]);

    if (word == vec[i]) {
      if (first_position == -1) first_position = i;
      ++cnt;
    }
  }
  if (first_position == -1) std::cout << -1 << std::endl;
  else {
    std::cout << cnt << " " << first_position << std::endl;
  }
  return 0;
}
