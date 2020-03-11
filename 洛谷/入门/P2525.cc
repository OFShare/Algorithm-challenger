#include<bits/stdc++.h>

using namespace std;
int n,a[10000];

int main() {
  cin>>n;
  for(int i=0;i<n;i++)   //读入数据
    cin>>a[i];
  if(prev_permutation(a,a+n))  //如果为真就输出数组
    for(int i=0;i<n;i++)
      cout<<a[i]<<" ";
  else cout<<"ERROR";   //否则输出ERROR
  return 0;
}
