/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-04-24 20:39:46 PM
 * File Name     : CF792C.cc
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
int n, cnt[N];

int main() {
  scanf("%s", A + 1);
  n = std::strlen(A + 1);
  int sum = 0;
  for (int i = 1; i <= n; ++i) {
    sum = (sum + A[i] - '0') % 3;
    cnt[(A[i] - '0') % 3]++;
  }
  if (sum == 0) printf("%s", A + 1), exit(0);
  // 首位后紧跟零的个数
  int zero = 0;
  for (int i = 2; i <= n; ++i) {
    if (A[i] == '0') ++zero;
    else break;
  }
  // std::cout << "zero: " << zero << std::endl;

  // 分别枚举删一位是否可行以及最优, 删两位是否可行以及最优, 都不行-1
  if (n > 1 && (cnt[sum] > 1 || (cnt[sum] == 1 && sum != ((A[1] - '0')) % 3) || (cnt[sum] == 1 && ((A[1] - '0') % 3) == sum && zero <= 1))) cnt[sum]--;
  else if (n > 2 && cnt[3 - sum] >= 2) cnt[3 - sum] -= 2;
  else if (n > 1 && cnt[sum]) cnt[sum]--;
  else printf("-1\n"), exit(0);

  bool leader_zero = true;
  for (int i = 1; i <= n; ++i) {
    if (A[i] == '0' && leader_zero) continue;
    if (cnt[(A[i] - '0') % 3]) {
      printf("%c", A[i]);
      cnt[(A[i] - '0') % 3]--;
      leader_zero = false;
    }
  }
  if (leader_zero) printf("0\n");
  return 0;
}
