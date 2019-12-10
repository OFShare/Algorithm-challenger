/*
 * Created by OFShare on 2019-12-10
 *
 */

#include <cstdio>
#include <cstring>
#include <algorithm>

const int maxn = 5e5 + 5;
int n, C;
struct node {
  int value, quantity;
  bool operator<(node &rhs) const {
    return value > rhs.value;
  }
}A[maxn];

int main() {
  scanf("%d %d", &n, &C);
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    int value, quantity;
    scanf("%d %d", &value, &quantity);
    // 超过C, 那么就可以直接支付了, 所以可以直接贡献, 它的数量就是可以贡献的周数
    if (value >= C) {
      ans += quantity;
      quantity = 0;
    }
    A[i].value = value;
    A[i].quantity = quantity;
  }

  std::sort(A + 1, A + 1 + n);
  while(true) {
    int rest = C;
    for (int i = 1; i <= n; ++i) {
      int cnt = std::min(A[i].quantity, rest / A[i].value);
      A[i].quantity -= cnt;
      rest -= cnt * A[i].value;
    }

    if (rest > 0) {
      // 这个地方只需要从小到大选一个硬币即可, 想一想为什么.
      // 因为假如说, 需要每周支付10美元, 现在某种硬币价值4美元, 那么10 / 4 等于2, 在不超过10美元的情况下, 最多选2枚.
      // 所以我再选一个硬币肯定可以超过10美元.
      // 这就是为什么只需再多选一枚硬币的原因.
      for (int i = n; i >= 1; --i) {
        if (A[i].quantity > 0) {
          A[i].quantity -= 1;
          rest -= A[i].value;
          break;
        }
      }
    }
    // 如果多选了一枚硬币, 还是没有能够支付C美元, 说明怎么也凑不足C美元了, 推出循环
    if (rest > 0) break;
    // 这里可以优化, 这是凑足一个C, 其实可以凑足一批C.
    ans += 1;
  }
  printf("%d\n", ans);
  return 0;
}
