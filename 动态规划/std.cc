/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-02-15 23:30:56 PM
 * File Name     : std.cc
 */

#include <bits/stdc++.h>

void debug() {
#ifdef Acui
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
}
using namespace std;
struct h{
  int k,t;
}x[2500];
int cmp(const h&a,const h&b)
{
  return a.k>b.k;
}
int max(int a,int b)
{
  return (a>b?a:b);
}
int f[2500][2500];
int pop,n,ans;
int main()
{
  debug();
  scanf("%d",&n);
  for (int i=1;i<=n;i++) scanf("%d %d",&x[i].k,&x[i].t) ;
  //k为挂钩数，t为喜悦值
  sort(x+1,x+n+1,cmp);//排序
  memset(f,-210000000,sizeof(f));//先预处理为最小值
  f[0][1]=0;//手机上原来就有个挂钩所以算作0；
  for (int i=1;i<=n;i++)
    for (int j=0;j<=n;j++)
      f[i][j]=max(f[i-1][j],f[i-1][max(j-x[i].k,0)+1]+x[i].t);
  ans=0; 
  for (int i=0;i<=n;i++)
    ans=max(ans,f[n][i]);//去看看最后的答案
  printf("%d",ans);
  return 0;
}
