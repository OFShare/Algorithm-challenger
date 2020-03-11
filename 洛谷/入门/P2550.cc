/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-03-11 21:31:46 PM
 * File Name     : P2550.cc
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
std::vector<int> lottery;
int ans[7 + 5];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= 7; ++i) {
    int x;
    scanf("%d", &x);
    lottery.push_back(x);
  }
  std::sort(lottery.begin(), lottery.end());

  for (int i = 1; i <= n; ++i) {
    std::vector<int> tmp;
    for (int j = 1; j <= 7; ++j) {
      int x;
      scanf("%d", &x);
      tmp.push_back(x);
    }
    std::sort(tmp.begin(), tmp.end());
    
    int cnt = 0;
    for (int j = 0; j < 7; ++j) {
      for (int k = 0; k < 7; ++k) 
        if (tmp[j] == lottery[k]) ++cnt;
    }
    // std::cout << "cnt: " << cnt << std::endl;
    ans[cnt]++;
  }
  for (int i = 7; i >= 1; --i) {
    printf("%d ", ans[i]);
  }
  return 0;
}
