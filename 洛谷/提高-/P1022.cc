/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-04-25 21:55:55 PM
 * File Name     : P1022.cc
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
char A[N];
int n, equal_index;

// 判断从start开始, 是否是整数, 标示[start, j]
int step(int start) {
  bool is_first = true;
  bool have_number = false;
  int i;
  for (i = start; i <= n; ++i) {
    if (A[i] >= 'a' && A[i] <= 'z') return i;
    if (A[i] == '=') return i - 1;

    if ((A[i] == '-' || A[i] == '+')) {
      if (have_number || is_first == false) return i - 1;
      is_first = false;
      continue;
    }
    if (A[i] >= '0' && A[i] <= '9') {
      have_number = true;
      continue;
    }
  }
  return i - 1;
}

// 返回[start, end]构成的整数
int number(int start, int end) {
  int ans = 0, leader = 1;
  for (int i = start; i <= end; ++i) {
    if (A[i] == '-') leader = -1;
    else if (A[i] == '+') leader = 1;
    else {
      assert(A[i] >= '0' && A[i] <= '9');
      ans += std::pow(10, end - i) * (A[i] - '0');
    }
  }
  return ans * leader;
}

// 返回从start开始的一元变量的整数部分值, 注意a=3这样的情况
int not_number(int start) {
  int i;
  for (i = start; ; ++i) {
    if (A[i] >= 'a' && A[i] <= 'z') {
      break;
    }
  }
  int ans = 0, end = i - 1, leader = 1;
  for (int k = start; k <= end; ++k) {
    if (A[k] == '-') leader = -1;
    else if (A[k] == '+') leader = 1;
    else {
      assert(A[k] >= '0' && A[k] <= '9');
      ans += std::pow(10, end - k) * (A[k] - '0');
      // std::cout << "A[k] - 0: " << A[k] - '0' << std::endl;
    }
  }
  if (A[start] >= '0' && A[start] <= '9') return ans * leader;
  // 特判, +a, -a, a
  if (end - start <= 0) return leader;
  return ans * leader;
}
int main() {
  scanf("%s", A + 1);
  n = std::strlen(A + 1);
  char op;
  for (int i = 1; i <= n; ++i) {
    if (A[i] >= 'a' && A[i] <= 'z') {
      op = A[i];
      break;
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (A[i] == '=') {
      equal_index = i;
      break;
    }
  }
  // std::cout << "not_number(1): " << not_number(1);
  // exit(0);
  
  // std::cout << "number(3, 4): " << number(3, 4) << std::endl;
  // std::cout << "number(5, 6): " << number(5, 6) << std::endl;
  // std::cout << "not_number(9): " << not_number(9) << std::endl;
  // exit(0);
  
  // 变量, 整数
  int left1 = 0, left2 = 0;
  int right1 = 0, right2 = 0;
  for (int i = 1; i <= equal_index - 1;) {
    int ret = step(i);
    // std::cout << "ret: " << ret << std::endl;
    if (A[ret] >= 'a' && A[ret] <= 'z') {
      left1 += not_number(i);
    } else {
      left2 += number(i, ret);
    }
    i = ret + 1;
  }
  // std::cout << "left1: " << left1 << std::endl;
  // std::cout << "left2: " << left2 << std::endl;
  for (int i = equal_index + 1; i <= n;) {
    int ret = step(i);
    if (A[ret] >= 'a' && A[ret] <= 'z') {
      right1 += not_number(i);
    } else {
      right2 += number(i, ret);
    }
    i = ret + 1;
  }
  // std::cout << "right1: " << right1 << std::endl;
  // std::cout << "right2: " << right2 << std::endl;
  // 解这个方程: left1_a + left2 = right1_a + right2
  // 特判5-5=10a, 10a=5-5
  double ans = (right2 - left2) * 1.0 / (left1 - right1 + 0.0);
  printf("%c=%.3lf\n", op, ans + 0.00000);
  return 0;
}
