/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-02-01 23:28:38 PM
 * File Name     : POJ-1426.cc
 */

#include <cstdio>

long long n, m;
bool founded;
void dfs(long long x, int depth) {
  if (depth >= 19 || founded)
    return ;
  if (x % n == 0) {
    m = x;
    founded = true;
    return ;
  }
  // x后面添0
  dfs(x * 10 + 0, depth + 1);
  // x后面添1
  dfs(x * 10 + 1, depth + 1);
}
int main() {
  while (scanf("%lld", &n) && n) {
    founded = false;
    dfs(1, 0);
    printf("%lld\n", m);
  }
  return 0;
}
