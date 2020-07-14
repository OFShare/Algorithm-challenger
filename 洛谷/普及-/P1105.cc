#include <bits/stdc++.h>

using namespace std;

int n,a[1001],b[1001],c[1001];

int main() {
  cin>>n;
  for(int i=1;i<=n;i++)cin>>a[i]>>b[i]>>c[i];
  for(int i=1;i<=n;i++){
    int sum1=0,sum2=0;
    for(int j=1;j<=n;j++)if(a[j]<a[i]&&b[j]<b[i]&&c[j]>b[i])if(a[sum1]<a[j])sum1=j;//左边下落
    cout<<sum1<<" ";
    for(int j=1;j<=n;j++)if(a[j]<a[i]&&b[j]<c[i]&&c[j]>c[i])if(a[sum2]<a[j])sum2=j;//右边下落
    cout<<sum2<<endl;
  }
}
