//
// created by OFShare on 2019-08-27
//

#include <bits/stdc++.h>

const int INF = 1e9;
const int maxn = 15 + 2;
int t;
int n;
struct node{
    char str[101];
    int deadline, time;
}A[maxn];

// dp[i]：整数i对应的集合课程都完成时，所能得到的最少扣分
int dp[1<<maxn];
// T[i]：dp[i]最优下，所需要的时间
int T[1<<maxn];
// pre[i]：整数i对应的集合课程都完成时最优的前驱(即选的哪一门课程，转移到i这个状态)
int pre[1<<maxn];

void output(int i){
    // 递归边界
    if(i==0) return ;
    int prek = (1<<pre[i])^i;
    output(prek);
    printf("%s\n", A[n-pre[i]].str);
}

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d", &n);
        for(int i=1;i<=n;++i){
            scanf("%s %d %d", A[i].str, &A[i].deadline, &A[i].time);
        }
        // 初始化
        std::fill(dp, dp+(1<<maxn), INF);
        dp[0] = 0;
        T[0] = 0;
        for(int i=1;i<(1<<n);++i){
            for(int j=0;j<n;++j){
                if((1<<j)&i){
                    int prek = (1<<j)^i;
                    // 选第j门课，下标从0开始
                    int reduce = T[prek] + A[n-j].time - A[n-j].deadline;
                    reduce = reduce > 0? reduce: 0;
                    if(dp[prek] + reduce < dp[i]){
                        dp[i] = dp[prek] + reduce;
                        T[i] = T[prek] + A[n-j].time;
                        pre[i] = j;
                    }
                }
            }
        }
        printf("%d\n", dp[(1<<n)-1]);
        output((1<<n)-1);
    }
    return 0;
}
