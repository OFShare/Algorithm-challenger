import random

def gen():
  n = random.randint(10, 15)
  G = random.randint(1, 10000)
  print(n, G)

  for i in range(1, n + 1):
    cost = random.randint(0, 10000)
    value = random.randint(0, 1000000)
    father = random.randint(1, i)
    print(cost, value, father)


if __name__ == '__main__':
  gen()
