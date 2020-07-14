/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-06-28 20:42:41 PM
 * File Name     : POJ-3977.cc
 */

//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <map>

#define ll long long

ll my_abs(ll x) {
  return x >= 0? x: -x;
}

void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 35 + 5;
const ll INF = 1e18;
std::vector<std::pair<ll, int> > s1, s2;
std::pair<ll, int> ans;

ll A[N], n;

void dfs(int pos, const int &end, ll sum, int cnt, std::vector<std::pair<ll, int> > &s) {
  // 递归的边界
  if (pos == end) {
    if (cnt) s.push_back({sum, cnt});
    return ;
  }
  // 不选
  dfs(pos + 1, end, sum, cnt, s);
  // 选
  dfs(pos + 1, end, sum + A[pos], cnt + 1, s);
}
int main() {
  while (scanf("%lld", &n) && n) {
    for (int i = 1; i <= n; ++i) {
      scanf("%lld", &A[i]);
    }
    s1.clear(), s2.clear();
    ans.first = INF, ans.second = 1e9;

    int mid = 1 + (n - 1) / 2 + 1;
    dfs(1, mid, 0, 0, s1);
    dfs(mid, n + 1, 0, 0, s2);
    std::sort(s1.begin(), s1.end());
    // 答案要么在左半部分, 要么在右边部分, 要么左边 + 右边部分
    int len1 = s1.size();
    for (int i = 0; i < len1; ++i) {
      if (my_abs(s1[i].first) < ans.first) ans.first = my_abs(s1[i].first), ans.second = s1[i].second;
      else if (my_abs(s1[i].first) == ans.first) ans.first = my_abs(s1[i].first), ans.second = std::min(ans.second, s1[i].second);
    }
    int len2 = s2.size();
    for (int i = 0; i < len2; ++i) {
      if (my_abs(s2[i].first) < ans.first) ans.first = my_abs(s2[i].first), ans.second = s2[i].second;
      else if (my_abs(s2[i].first) == ans.first) ans.first = my_abs(s2[i].first), ans.second = std::min(ans.second, s2[i].second);
    }

    for (int i = 0; i < len2; ++i) {
      std::vector<std::pair<ll, int> >::iterator ite = std::lower_bound(s1.begin(), s1.end(), std::make_pair(-s2[i].first, 0));
      if (ite != s1.end()) {
        if (my_abs(ite -> first + s2[i].first) == ans.first) 
          ans.first = my_abs(ite -> first + s2[i].first),
          ans.second = std::min(ans.second, ite -> second + s2[i].second);
        else if (my_abs(ite -> first + s2[i].first) < ans.first) 
          ans.first = my_abs(ite -> first + s2[i].first),
          ans.second = ite -> second + s2[i].second;
      }
      if (ite != s1.begin()) {
        --ite;
        if (my_abs(ite -> first + s2[i].first) == ans.first) 
          ans.first = my_abs(ite -> first + s2[i].first),
          ans.second = std::min(ans.second, ite -> second + s2[i].second);
        else if (my_abs(ite -> first + s2[i].first) < ans.first) 
          ans.first = my_abs(ite -> first + s2[i].first),
          ans.second = ite -> second + s2[i].second;
      }
    }
    printf("%lld %d\n", ans.first, ans.second);
  }
  return 0;
}
