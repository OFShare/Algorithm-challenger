//
// created by OFShare on 2019-08-31
//

#include <bits/stdc++.h>

const int INF = 1e5;
const int maxn = 1e3 + 5;
int n;
char A[maxn];
// dp[i]：前i个字符组成的最少的回文串组数
int dp[maxn];

int is_palindrome(int start_, int end_){
    if((start_ > end_) || (start_ == end_))
        return 1;
    if(A[start_] == A[end_])
        return is_palindrome(start_+1, end_-1);
    return INF;
}

int main(){
    scanf("%d", &n);
    while(n--){
        scanf("%s", A+1);
        // 初始化
        std::fill(dp, dp+maxn, INF);
        dp[1] = 1;

        for(int i=1; i<=strlen(A+1); ++i){
            // 考虑整个串构成一个回文串
            dp[i] = std::min(dp[i], is_palindrome(1, i));
            for(int j=1; j<i; ++j){
                dp[i] = std::min(dp[i], dp[j] + is_palindrome(j+1, i));
            }
        }
        printf("%d\n", dp[strlen(A+1)]);
    }
    return 0;
}
