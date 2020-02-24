/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-02-24 11:50:36 AM
 * File Name     : P1321.cc
 */

#include <bits/stdc++.h>

void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 255 + 5;
char A[N];
char str_boy[N];
char str_girl[N];

int main() {
  scanf("%s", A + 1);
  int ans_boy = 0, ans_girl = 0;
  char pre_char;
  std::set<char> st_boy, st_girl;
  st_boy.insert('b');
  st_boy.insert('o');
  st_boy.insert('y');

  st_girl.insert('g');
  st_girl.insert('i');
  st_girl.insert('r');
  st_girl.insert('l');

  // boy: 维护每个字母的父亲节点, b的父亲节点设置为'x', 'o'的父亲节点为'b', 'y'的父亲节点为'o'
  str_boy['b'] = 'x'; str_boy['o'] = 'b'; str_boy['y'] = 'o';
  str_girl['g'] = 'x'; str_girl['i'] = 'g'; str_girl['r'] = 'i'; str_girl['l'] = 'r';

  for (int i = 1; i <= strlen(A + 1); ++i) {
    if (i == 1 && st_boy.count(A[i]) >= 1) ++ans_boy, pre_char = A[i];
    else if (i == 1 && st_girl.count(A[i]) >= 1) ++ans_girl, pre_char = A[i];
    if (i == 1) continue;

    if (st_boy.count(A[i]) >= 1 && str_boy[A[i]] == pre_char) {
      pre_char = A[i];
      continue;
    }
    if (st_boy.count(A[i]) >= 1 && str_boy[A[i]] != pre_char) {
      ++ans_boy;
      pre_char = A[i];
      continue;
    }

    if (st_girl.count(A[i]) >= 1 && str_girl[A[i]] == pre_char) {
      pre_char = A[i];
      continue;
    }
    if (st_girl.count(A[i]) >= 1 && str_girl[A[i]] != pre_char) {
      ++ans_girl;
      pre_char = A[i];
      continue;
    }
  }
  printf("%d\n%d\n", ans_boy, ans_girl);
  return 0;
}
