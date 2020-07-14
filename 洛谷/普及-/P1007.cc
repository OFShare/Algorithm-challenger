#include <bits/stdc++.h>

using namespace std;

int main() {
  int n,l,p,maxv=0,minv=0;
  scanf("%d%d",&l,&n);
  for(int i=1;i<=n;i++)
  {
    scanf("%d",&p);
    maxv=max(maxv,max(l-p+1,p));
    minv=max(minv,min(l-p+1,p));
  }
  printf("%d %d",minv,maxv);
  return 0;
}
