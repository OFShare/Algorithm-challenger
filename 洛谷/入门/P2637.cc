/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-03-10 20:53:18 PM
 * File Name     : P2637.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

int n, m;
std::vector<int> vec;
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; ++i)  {
    int x;
    scanf("%d", &x);
    vec.push_back(x);
  }
  std::sort(vec.begin(), vec.end());
  int ans = 0, price;
  for (int i = 0; i < vec.size(); ++i) {
    if ((vec.size() - i) * vec[i] > ans) {
      price = vec[i];
      ans = (vec.size() - i) * vec[i];
    }
  }
  printf("%d %d\n", price, ans);
  return 0;
}
