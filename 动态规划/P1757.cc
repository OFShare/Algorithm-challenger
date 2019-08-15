//
// created by OFShare on 2019-08-15
//
// https://www.luogu.org/problem/P1757

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e2 + 10;
const int maxm = 1e3 + 10;
// dp[i][j]: 前i组背包，装进容量不大于j时，能获得的最大价值
int dp[maxn][maxm];

struct node{
    int w,value;
};
vector<node> A[maxn];
int m,n;
set<int> st;

int main(){
    scanf("%d %d",&m,&n);
    for(int i=1;i<=n;++i){
        int x,y,z;
        scanf("%d %d %d", &x,&y,&z);
        A[z].push_back({x,y});
        st.insert(z);
    }
    int cnt = st.size();
    for(int i=1;i<=cnt;++i){
        for(int j=0;j<=m;++j){
            // 遍历第i组，不选，或选其中的一个
            dp[i][j] = dp[i-1][j];
            for(int k=0;k<A[i].size();++k){
                int w = A[i][k].w;
                int value = A[i][k].value;
                if(j-w>=0)
                    dp[i][j] = std::max(dp[i][j], dp[i-1][j-w] + value);
            }
        }
    }
    printf("%d",dp[cnt][m]);
    return 0;
}
