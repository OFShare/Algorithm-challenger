#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define ms(s) memset(s,0,sizeof(s))

const double PI = 3.141592653589;
const int INF = 0x3fffffff;

int c[100010], v[100010];
vector<int> Tree[100010];
int dp[505][10010];
int n, maxg;

void solve(int root, int g) {
  for(int i = 0; i < Tree[root].size(); i++) {
    int child = Tree[root][i];
    if(Tree[child].empty()) {
      for(int j = g; j >= c[child]; j--) {
        dp[root][j] = max(dp[root][j], dp[root][j-c[child]]+v[child]);
      }
    }
    else {
      for(int j = 0; j <= g-c[child]; j++) {
        dp[child][j] = dp[root][j];
      }
      solve(child, g-c[child]);
      for(int j = g; j >= c[child]; j--) {
        dp[root][j] = max(dp[root][j], dp[child][j-c[child]]+v[child]);
      }
    }
  }
}


int main() {
  ios::sync_with_stdio(false);

  int fa;
  while(cin >> n >> maxg) {
    //init
    for(int i = 0; i <= 500; i++)
      Tree[i].clear();
    ms(dp);

    for(int i = 1; i <= n; i++) {
      cin >> c[i] >> v[i] >> fa;
      if(fa == i)
        Tree[0].push_back(i);
      else
        Tree[fa].push_back(i);
    }
    solve(0, maxg);
    cout << dp[0][maxg] << endl;
  }
  return 0;
}
