#include <bits/stdc++.h>

const int N = 1e6 + 5;
int a[N];

using namespace std;

int main() {
  int n,i,time,high,s;//high表示最高楼层,s表示不重复楼层的数目 
  cin>>n;
  for(i=0;i<n;i++)   
    cin>>a[i];   
  sort(a,a+n);//快排   
  high=a[n-1];//最高楼层赋给high 
  s=unique(a,a+n)-a;//计算不重复楼层的数目 
  time=high*(4+6)+n;//每层上下4+6秒*最高层+总共要下电梯的人数*1s 
  for(i=0;i<s;i++)
    time+=5; 
  cout<<time<<endl;
  return 0;   
}
