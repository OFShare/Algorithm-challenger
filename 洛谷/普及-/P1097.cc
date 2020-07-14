#include<bits/stdc++.h>

using namespace std;

int main() {
  map <int,int> a;  //把它看成数组
  set <int> b;
  int n,i,q;
  cin>>n;
  for(i=1; i<=n; i++) {
    scanf("%d",&q);
    a[q]++;
    b.insert(q);
  }
  for(set<int>::iterator it=b.begin(); it!=b.end(); it++) //迭代器
    printf("%d %d\n",*it,a[*it]);
}
