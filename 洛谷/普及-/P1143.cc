/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-03-15 17:21:27 PM
 * File Name     : P1143.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 1e5 + 5;
int n, m;
char A[N];
std::map<char, int> mp;
std::map<int, char> mp2;

void init() {
  for (char i = '0'; i <= '9'; ++i)
    mp[i] = i - '0';
  mp['A'] = 10;
  mp['B'] = 11;
  mp['C'] = 12;
  mp['D'] = 13;
  mp['E'] = 14;
  mp['F'] = 15;
  
  for (int i = 0; i <= 9; ++i)
    mp2[i] = i + '0';
  mp2[10] = 'A';
  mp2[11] = 'B';
  mp2[12] = 'C';
  mp2[13] = 'D';
  mp2[14] = 'E';
  mp2[15] = 'F';
}

// n进制转10进制
int n_decimal_ten() {
  int ret = 0;
  int p = std::strlen(A) - 1;
  for (int i = 0; i < std::strlen(A); ++i) {
    ret += mp[A[i]] * std::pow(n, p--);
  }
  return ret;
}
// 10进制转m进制
std::vector<char> vec;
void ten_decimal_m(int number) {
  int start = 0;
  while (std::pow(m, start) <= number)
    ++start;
  start -= 1;
  for (int i = start; i >= 0; --i) {
    // std::cout << "i: " << i << std::endl;
    // std::cout << "std::pow(m, i): " << std::pow(m, i) << std::endl;
    vec.push_back(mp2[number / std::pow(m, i)]);
    number %= (int)std::pow(m, i);
  }
}
int main() {
  scanf("%d %s %d", &n, A, &m);
  init();
  int ret = n_decimal_ten();
  ten_decimal_m(ret);
  for (int i = 0; i < vec.size(); ++i)
    printf("%c", vec[i]);
}
