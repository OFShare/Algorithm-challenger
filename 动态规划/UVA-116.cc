//
// created by OFShare on 2019-08-21
//

#include <bits/stdc++.h>

const int maxn = 1e2 + 5;
const int INF = 1e9;
int m,n;
int A[maxn][maxn];

// sum[i][j]:从第一列出发，走到当前位置(i, j)的最小值。但是这样定义的状态不太好找字典序最小的最短路径
// 所以本题用的是这样定义的状态，sum[i][j]:从当前位置(i, j)出发，走到最后一列的最小值。
// 仔细体会这两种定义状态的异同
int sum[maxn][maxn];

int dfs(int i, int j){
    // 记忆化，以及递归边界
    if(sum[i][j]!=-1) return sum[i][j];
    if(j==n){
        return sum[i][j] = A[i][j];
    }

    int ans = INF;
    // 第一种情况
    if(i==1) ans = std::min(ans, dfs(m, j+1) + A[i][j]);
    else ans = std::min(ans, dfs(i-1, j+1) + A[i][j]);
    // 第二种情况
    ans = std::min(ans, dfs(i, j+1) + A[i][j]);
    // 第三种情况
    if(i==m) ans = std::min(ans, dfs(1, j+1) + A[i][j]);
    else ans = std::min(ans, dfs(i+1, j+1) + A[i][j]);

    return sum[i][j] = ans;
}

int main(){
    while(scanf("%d %d",&m,&n)!=-1){
        for(int i=1;i<=m;++i){
            for(int j=1;j<=n;++j){
                scanf("%d",&A[i][j]);
            }
        }
        // 初始化
        for(int i=0;i<maxn;++i){
            for(int j=0;j<maxn;++j){
                sum[i][j] = -1;
            }
        }

        int minPath = INF;
        for(int i=1;i<=m;++i){
            minPath = std::min(minPath, dfs(i, 1));
        }
        std::vector<int> path;
        int startRow;
        for(int i=1;i<=m;++i){
            if(dfs(i, 1) == minPath){
                startRow = i;
                break;
            }
        }
        path.push_back(startRow);
        int leftPathLen = minPath;
        int currentRow = startRow;
        for(int j=1;j<=n-1;++j){
            if(currentRow == 1){
                if(leftPathLen == sum[currentRow][j+1] + A[currentRow][j]){
                    leftPathLen -= A[currentRow][j];
                    currentRow = currentRow;
                    path.push_back(currentRow);
                    continue;
                }
                if(leftPathLen == sum[currentRow+1][j+1] + A[currentRow][j]){
                    leftPathLen -= A[currentRow][j];
                    currentRow = currentRow+1;
                    path.push_back(currentRow);
                    continue;
                }
                if(leftPathLen == sum[m][j+1] + A[currentRow][j]){
                    leftPathLen -= A[currentRow][j];
                    currentRow = m;
                    path.push_back(currentRow);
                    continue;
                }
            }

            if(currentRow == m){
                if(leftPathLen == sum[1][j+1] + A[currentRow][j]){
                    leftPathLen -= A[currentRow][j];
                    currentRow = 1;
                    path.push_back(currentRow);
                    continue;
                }
                if(leftPathLen == sum[currentRow-1][j+1] + A[currentRow][j]){
                    leftPathLen -= A[currentRow][j];
                    currentRow = currentRow-1;
                    path.push_back(currentRow);
                    continue;
                }
                if(leftPathLen == sum[currentRow][j+1] + A[currentRow][j]){
                    leftPathLen -= A[currentRow][j];
                    currentRow = currentRow;
                    path.push_back(currentRow);
                    continue;
                }
            }

            if(currentRow >1 && currentRow <m){
                if(leftPathLen == sum[currentRow-1][j+1] + A[currentRow][j]){
                    leftPathLen -= A[currentRow][j];
                    currentRow = currentRow-1;
                    path.push_back(currentRow);
                    continue;
                }
                if(leftPathLen == sum[currentRow][j+1] + A[currentRow][j]){
                    leftPathLen -= A[currentRow][j];
                    currentRow = currentRow;
                    path.push_back(currentRow);
                    continue;
                }
                if(leftPathLen == sum[currentRow+1][j+1] + A[currentRow][j]){
                    leftPathLen -= A[currentRow][j];
                    currentRow = currentRow+1;
                    path.push_back(currentRow);
                    continue;
                }
            }
        }
        for(int i=0;i<path.size();++i){
            if(i==0){
                printf("%d", path[i]);
            }else{
                printf(" %d", path[i]);
            }
        }
        printf("\n%d\n",minPath);
    }
    return 0;
}
