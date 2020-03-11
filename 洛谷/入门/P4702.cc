#include <bits/stdc++.h>

using namespace std;

const int maxN=105; //n最大是100，maxN开的稍微大一点就行
int n, a[maxN];
long long sum=0;
//上面是定义的常量和变量

int main() {
  scanf("%d", &n);
  for(int i=1; i<=n; i++) {
    scanf("%d", &a[i]);
    sum+=a[i]; //累加就行，你如果用前缀和a数组就不能开整型了
  }
  if(sum&1) printf("Alice"); //if语句中用的是位运算，通俗理解就是判断sum是否为奇数
  //如果sum是奇数输出Alice
  else printf("Bob"); //反之输出Bob
  return 0;
}
