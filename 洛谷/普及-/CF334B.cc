/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-04-25 17:53:29 PM
 * File Name     : CF334B.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

std::set<std::pair<int, int> > st;
std::set<int> X, Y;

int main() {
  for (int i = 1; i <= 8; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    X.insert(x);
    Y.insert(y);
    st.insert({x, y});
  }
  if (X.size() != 3 || Y.size() != 3 || st.size() != 8) printf("ugly\n"), exit(0);
  int i = 1, j = 1;
  for (auto it = X.begin(); i <= 3; ++i, ++it) {
    j = 1;
    for (auto it2 = Y.begin(); j <= 3; ++j, ++it2) {
      if (i == 2 && j == 2) continue; 
      int x = *it, y = *it2;
      if (st.count({x, y}) != 1) printf("ugly\n"), exit(0);
    }
  }
  printf("respectable\n");
  return 0;
}
