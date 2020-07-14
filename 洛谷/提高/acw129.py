import math

# 计算组合C(n, m)
def C(n, m):
  return math.factorial(n) // math.factorial(m) // math.factorial(n - m)

if __name__ == '__main__':
  n = (int)(input())
  ret1 = C(2 * n, n)
  ret2 = C(2 * n, n - 1)
  print((int)(ret1 - ret2))
