#include <bits/stdc++.h> 
using namespace std;
int n, m, k, a, b, ans;
int s[5005][5005];
bool pd(int x, int y) { //判断是否越界 
  if(x < 1 || y < 1 || x > n || y > n) return 0;
  return 1;
}
int main() {
  scanf("%d%d%d", &n, &m, &k); //读入 
  for(int i = 1; i <= m + k; i++) { //由于计算火把和萤石的步骤很像，所以合并了 
    scanf("%d%d", &a, &b); //读入坐标 
    for(int x = -2; x <= 2; x++)
      for(int y = -2; y <= 2; y++) //枚举5*5的方阵(通过计算距离) 
        if((i > m || abs(x) + abs(y) <= 2) && pd(x + a, b + y))
          //如果是萤石(i > m)或者x与y的坐标差的和不超过2(想一想为什么)并且
          //没有越界就标记 
          s[x + a][b + y]++;
  }
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)
      ans += s[i][j] == 0; //枚举每一个方格，看看是不是==0(即没有亮光) 
  printf("%d\n", ans); //输出结果 
  return 0;
}
