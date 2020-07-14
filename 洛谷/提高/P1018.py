#  Author        : OFShare
#  E-mail        : OFShare@outlook.com
#  Created Time  : 2020-04-20 22:59:25 PM
#  File Name     : P1018.py

import math
import numpy as np

# number = []
# dp = []

def dfs(i, j):
  global number, dp
  # 递归的边界
  if j == 0:
    return number[1][i]
  # 记忆化
  if dp[i][j] != -1:
    return dp[i][j]

  ret = -1e9
  for k in range(i):
    k = k + 1
    if k == i:
      break
    ret = max(ret, dfs(k, j - 1) * number[k + 1][i])
  dp[i][j] = ret
  return dp[i][j]

if __name__ == '__main__':
  n, k = map(int, input().split())
  s = '1' + input()

  # global number, dp
  number = [[-1 for j in range(n + 1)] for i in range(n + 1)]
  dp = [[-1 for j in range(n + 1)] for i in range(n + 1)]
  for i in range(1, n + 1):
    for j in range(i, n + 1):
      number[i][j] = int(s[i: j + 1])
  print(dfs(n, k))
