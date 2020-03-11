/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-03-10 17:25:25 PM
 * File Name     : P2415.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
#ifdef Acui
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
}

long long tmp, num=0, sum=0;
int main() {
  while (std::cin >> tmp) {sum += tmp; num++;}//读入集合元素个数num和元素和sum
  std::cout << (long long)(sum * pow(2,num-1));//必须显式地转换为long long输出
  return 0;
}
