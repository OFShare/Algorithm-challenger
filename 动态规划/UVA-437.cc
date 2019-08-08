//
// created by OFShare on 2019-08-08
//

#include <bits/stdc++.h>

const int maxn = 30+10;
int n;
struct node{
    int v[5];
}A[maxn];
int vis[maxn][maxn];

// 获得第i个block的除了第j条边的另外两条边
std::vector<int> get_base(int i, int j){
    std::vector<int> ret(3);
    int cnt = 0;
    for(int k=1;k<=3;++k){
        if(k!=j)
            ret[++cnt] = A[i].v[k];
    }
    return ret;
}

// dfs表示第i个block, 且它的第j条边作为高，从它出发能堆叠的最大高度
int dfs(int i, int j){
    // 记忆化，如果这个状态原来已经被搜索过了的话，直接返回
    if(vis[i][j]) return vis[i][j];
    int ans = A[i].v[j];
    std::vector<int> base_i= get_base(i, j);
    // 遍历第k个block，它的第u条边，能否堆叠在第i个block上
    for(int k=1;k<=n;++k){
        for(int u=1;u<=3;++u){
            std::vector<int> base_k = get_base(k, u);
            if(base_i[1] > base_k[1] && base_i[2] > base_k[2])
                ans = std::max(ans, A[i].v[j] + dfs(k, u));
        }
    }
    return vis[i][j] = ans;
}

int main(){
#ifdef OFShare
    std::freopen("datain.txt", "r", stdin);
    std::freopen("dataout.txt", "w", stdout);
#endif
    int kase = 0;
    while(scanf("%d",&n)&&n){
        memset(vis,0,sizeof vis);
        for(int i=1;i<=n;++i){
            scanf("%d %d %d",&A[i].v[1], &A[i].v[2], &A[i].v[3]);
            std::sort(A[i].v+1, A[i].v+1+3);
        }
        // 遍历枚举每个block当作基地块
        int ans = 0;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=3;++j){
                ans = std::max(ans, dfs(i, j));
            }
        }
        printf("Case %d: maximum height = %d\n",++kase, ans);
    }
    return 0;
}
