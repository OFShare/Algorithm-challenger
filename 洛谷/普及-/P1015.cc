/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-03-12 22:22:51 PM
 * File Name     : P1015.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 1e2 + 5;
int n;
char M[N];

std::map<char, int> mp;
std::map<int, char> mp2;
void init() {
  mp['0'] = 0, mp['1'] = 1, mp['2'] = 2, mp['3'] = 3;
  mp['4'] = 4, mp['5'] = 5, mp['6'] = 6, mp['7'] = 7;
  mp['8'] = 8, mp['9'] = 9;
  mp['A'] = 10, mp['B'] = 11;
  mp['C'] = 12, mp['D'] = 13;
  mp['E'] = 14, mp['F'] = 15;

  mp2[0] = '0', mp2[1] = '1', mp2[2] = '2', mp2[3] = '3';
  mp2[4] = '4', mp2[5] = '5', mp2[6] = '6', mp2[7] = '7';
  mp2[8] = '8', mp2[9] = '9', mp2[10] = 'A', mp2[11] = 'B';
  mp2[12] = 'C', mp2[13] = 'D', mp2[14] = 'E', mp2[15] = 'F';
}
std::string one_step(std::string rhs) {
  std::string lhs = rhs;
  std::reverse(lhs.begin(), lhs.end());

  // 模拟高精度加法
  int add = 0;
  for (int i = rhs.size() - 1; i >= 0; --i) {
    int a = (add + mp[lhs[i]] + mp[rhs[i]]) % n; 
    int b = (add + mp[lhs[i]] + mp[rhs[i]]) / n;

    rhs[i] = mp2[a];
    add = b;
  }
  if (add) return std::string("") + mp2[add] + rhs;
  else return rhs;
}

bool valid(std::string rhs) {
  std::string lhs = rhs;
  std::reverse(lhs.begin(), lhs.end());
  return lhs == rhs;
}
int main() {
  init();
  scanf("%d %s", &n, M + 1);

  std::string s(M + 1);
  for (int step = 0; step <= 30; ++step) {
    if (valid(s)) {
      printf("STEP=%d\n", step);
      return 0;
    }
    s = one_step(s);
  }
  printf("Impossible!\n");
  return 0;
}
