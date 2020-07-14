/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-03-15 12:08:05 PM
 * File Name     : P1079.cc
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
char K[N], C[N];
char mp[255 + 5][255 + 5];

// 构建表
void init() {
  int skip = 0;
  for (char i = 'A'; i <= 'Z'; ++i) {
    char secret = 'A' + (skip++);
    for (char j = 'A'; j <= 'Z'; ++j) {
      mp[i][j] = secret++;
      if (secret > 'Z')
        secret = 'A';
    }
  }
}

// 转为大写
char upper(char ch) {
  if (ch >= 'A' && ch <= 'Z') return ch;
  else return ch - 'a' + 'A';
}
// 转为小写
char lower(char ch) {
  if (ch >= 'a' && ch <= 'z') return ch;
  else return ch - 'A' + 'a';
}
int main() {
  scanf("%s %s", K + 1, C + 1);
  init();
  int p1 = 1, p2 = 1;
  std::string ans = "";

  for (int i = 1; i <= std::strlen(C + 1); ++i) {
    // 枚举明文
    for (char m = 'A'; m <= 'Z'; ++m) {
      char tmp1 = upper(K[p1]);
      char tmp2 = upper(mp[tmp1][m]);
      // 找到了
      if (tmp2 == upper(C[p2])) {
        if (C[p2] >= 'A' && C[p2] <= 'Z') ans += upper(m);
        else  ans += lower(m);
        break;
      }
    }
    ++p2;
    ++p1;
    if (p1 == std::strlen(K + 1) + 1)
      p1 = 1;
  }
  printf("%s\n", ans.c_str());
  return 0;
}
