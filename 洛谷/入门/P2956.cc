#include <bits/stdc++.h>

bool t[250][250];//开个数组，方便记录耕田的情况。

int main(){
  int i,x,y,n,j,s=0,a,b,c,d;
  scanf("%d %d %d",&x,&y,&n);
  while(n--){ //在线，边读边做。
    scanf("%d %d %d %d",&a,&b,&c,&d);
    for(i=a;i<=c;i++)
      for(j=b;j<=d;j++)
        t[i][j]=1;//把处于在耕田的长方形里的面积，用“1”把全部都记录下来。
  }
  for(i=1;i<=x;i++)
    for(j=1;j<=y;j++)
      if(t[i][j]) s++;//因为是在主函数外开的数组，所以初始值都是0。是一的就s++，把耕过的田的总数给算出来
  printf("%d\n",s);//输出。
  return 0;
}
