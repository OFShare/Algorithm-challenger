import random

def func():
  n = random.randint(2000, 2000)
  print(n)
  for i in range(n):
    a = random.randint(2000, 2000)
    b = random.randint(1000000, 1000000)
    print(a, b)
if __name__ == '__main__':
  func()
