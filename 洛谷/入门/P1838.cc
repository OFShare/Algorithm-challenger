/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-02-27 12:08:08 PM
 * File Name     : P1838.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 18;
int mp[N][N];
bool check(int x) {
  if (mp[1][1] == x && mp[2][1] == x && mp[3][1] == x) return true;
  if (mp[1][1] == x && mp[2][2] == x && mp[3][3] == x) return true;
  if (mp[1][1] == x && mp[1][2] == x && mp[1][3] == x) return true;
  
  if (mp[1][2] == x && mp[2][2] == x && mp[3][2] == x) return true;

  if (mp[1][3] == x && mp[2][2] == x && mp[3][1] == x) return true;
  if (mp[1][3] == x && mp[2][3] == x && mp[3][3] == x) return true;
  
  return false;
}
int main() {
  char str[N];
  scanf("%s", str + 1);
  // turn = 1表示轮到小a下, 用1表示
  int turn = 1;
  for (int i = 1; i <= std::strlen(str + 1); ++i) {
    int a = str[i] - '0';
    if (a == 1) mp[1][1] = turn, turn = 1 - turn;
    if (a == 2) mp[1][2] = turn, turn = 1 - turn;
    if (a == 3) mp[1][3] = turn, turn = 1 - turn;
    if (a == 4) mp[2][1] = turn, turn = 1 - turn;
    if (a == 5) mp[2][2] = turn, turn = 1 - turn;
    if (a == 6) mp[2][3] = turn, turn = 1 - turn;
    if (a == 7) mp[3][1] = turn, turn = 1 - turn;
    if (a == 8) mp[3][2] = turn, turn = 1 - turn;
    if (a == 9) mp[3][3] = turn, turn = 1 - turn;
  }
  if (check(1)) printf("xiaoa wins.\n");
  else if (check(0)) printf("uim wins.\n");
  else printf("drew.\n");
}
