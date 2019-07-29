//
// created by OFShare on 2019-07-24
//

#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const int mod = 1e9;
int n,ans;

void dfs(int n, int power){
    if(n==0){
        ans = (ans+1)%mod;
        return ;
    }
    for(int i=power;std::pow(2,i)<=n;++i){
        dfs(n-std::pow(2,i),i);
    }
}
int main(){
    scanf("%d",&n);
    dfs(n,0);
    printf("%d",ans);
    return 0;
}
