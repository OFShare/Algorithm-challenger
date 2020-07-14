/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-03-15 13:48:10 PM
 * File Name     : P1104.cc
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
struct node {
  std::string name;
  int year, month, day;
  int id;
  bool operator<(const node &rhs) const {
    if (year != rhs.year) return year < rhs.year;
    else if (month != rhs.month) return month < rhs.month;
    else if (day != rhs.day) return day < rhs.day;
    return id > rhs.id;
  }
}A[N];

int main() {
  std::cin >> n;
  for (int i = 1; i <= n; ++i) {
    std::cin >> A[i].name >> A[i].year >> A[i].month >> A[i].day;
    A[i].id = i;
  }
  // 排序后输出
  std::sort(A + 1, A + 1 + n);
  for (int i = 1; i <= n; ++i) {
    std::cout << A[i].name << std::endl;
  }
  return 0;
}
