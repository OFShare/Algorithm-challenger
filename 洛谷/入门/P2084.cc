/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-03-08 19:45:47 PM
 * File Name     : P2084.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 1e3 + 5;
int M;
char A[N];

std::string ans;
void dfs(int x) {
  if (x == 0) return ;
  if (x >= 0) dfs(x / 10), ans.push_back(char(x % 10 + '0'));
}
int main() {
  debug();
  scanf("%d %s", &M, A + 1);
  bool is_first = true;
  for (int i = 1, j = strlen(A + 1) - 1; i <= strlen(A + 1); ++i, --j) {
    if (A[i] == '0') continue;
    if (is_first) {
      ans.push_back(A[i]);
      ans.push_back('*');
      ans.push_back(char(M + '0'));
      ans.push_back('^');
      if (j == 0) ans.push_back('0');
      else dfs(j);
      is_first = false;
    } else {
      ans.push_back('+');
      ans.push_back(A[i]);
      ans.push_back('*');
      ans.push_back(char(M + '0'));
      ans.push_back('^');
      if (j == 0) ans.push_back('0');
      else dfs(j);
    }
  }
  printf("%s\n", ans.c_str());
  return 0;
}
