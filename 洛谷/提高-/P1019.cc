/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-03-21 11:19:26 AM
 * File Name     : P1019.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 20 + 5;
int n;
std::vector<std::string> vec;
int cnt[N];
int ans_length = 1;

std::string match(std::string lhs, std::string rhs) {
  // 枚举长度
  for (int i = 1; i < lhs.size(); ++i) {
    if (i >= rhs.size()) break;
    bool ok = true;
    if (lhs.substr(lhs.size() - i, i) != rhs.substr(0, i)) ok = false;
    if (ok) {
      std::string ret = lhs;
      for (int j = i; j < rhs.size(); ++j) ret += rhs[j];
      return ret;
    }
  }
  return "";
}
void dfs(std::string str) {
  // 更新答案
  ans_length = std::max(ans_length, (int)str.size());
  for (int i = 0; i < n; ++i) {
    if (cnt[i] >= 2) continue;
    std::string ret = match(str, vec[i]);
    if (ret.empty()) continue;
    cnt[i]++;
    dfs(ret);
    cnt[i]--;
  }
}
int main() {
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::string str;
    std::cin >> str;
    vec.push_back(str);
  }
  char start;
  std::cin >> start;
  for (int i = 0; i < n; ++i) {
    if (vec[i][0] == start) {
      ++cnt[i];
      dfs(vec[i]);
      --cnt[i];
    }
  }
  std::cout << ans_length << std::endl;
  // std::cout << "string: " << match("touch", "cheat") << std::endl;
  return 0;
}
