/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-05-24 22:56:08 PM
 * File Name     : 644F.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
#ifdef Acui
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
}

const int N = 10 + 5;
int t, n, m;
char A[N][N];

// 找到不等的下标位置
std::vector<int> find(int i, int j) {
  std::vector<int> ret;
  for (int k = 1; k <= m; ++k) {
    if (A[i][k] != A[j][k]) {
      ret.push_back(k);
    }
  }
  return ret;
}

bool compare(char tmp[N]) {
  for (int i = 1; i <= n; ++i) {
    int cnt = 0;
    for (int k = 1; k <= m; ++k) {
      if (A[i][k] != tmp[k]) ++cnt;
      if (cnt >= 2) return false;
    }
  }
  return true;
}
int main() {
  debug();
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
      scanf("%s", A[i] + 1);
    }
    bool ok = true, found = false;
    if (n == 1) {
      printf("%s\n", A[1] + 1);
      continue;
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (i != j) {
          std::vector<int> ret = find(i, j);
          if (ret.size() >= 3) {
            ok = false;
            break;
          }
          // 分类讨论
          char tmp[N];
          bool re;
          if (ret.size() == 0) {
            std::copy_n(A[i] + 1, m, tmp + 1); 
            re = compare(tmp);
          } else if (ret.size() == 1) {
            std::copy_n(A[i] + 1, m, tmp + 1); 
            re = compare(tmp);
            if (re == false) {
              std::copy_n(A[j] + 1, m, tmp + 1); 
              re = compare(tmp);
            }
          } else if (ret.size() == 2) {
            std::copy_n(A[i] + 1, m, tmp + 1);
            tmp[m] = A[j][m];
            re = compare(tmp);
            if (re == false) {
              std::copy_n(A[j] + 1, m, tmp + 1);
              tmp[m] = A[i][m];
              re = compare(tmp);
            }
          }
          if (re) {
            tmp[m + 1] = '\0';
            found = true;
            printf("%s\n", tmp + 1);
            break;
          }
        }
      }
      if (ok == false) break;
      if (found == true) break;
    }
    if (ok == false) printf("-1\n");
  }
  return 0;
}
