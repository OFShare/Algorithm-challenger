/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-02-02 11:43:35 AM
 * File Name     : POJ-3414.cc
 */

//#include <bits/stdc++.h>
#include <cstdio>
#include <queue>
#include <cmath>
#include <cstring>
#include <string>

void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 1e2 + 5;
int A, B, C;

struct node {
  int a_cup, b_cup;
  int step;
  // 记录从初始状态到该状态的操作过程
  std::vector<std::string> op;
  void decode() {
    printf("%d\n", step);
    for (int i = 0; i < op.size(); ++i) {
      printf("%s\n", op[i].c_str());
    }
  }
}ans;

bool vis[N][N];
int bfs(node s) {
  std::queue<node> que;
  que.push(s);

  while (!que.empty()) {
    node p = que.front();
    que.pop();
    int a_cup = p.a_cup, b_cup = p.b_cup, step = p.step;
  
    // 找到了
    if (a_cup == C || b_cup == C) {
      ans = p;
      return 0;
    }
    vis[a_cup][b_cup] = true;
    std::vector<std::string> op_copy;
    std::string str;

    // 尝试fill A
    op_copy = p.op;
    str = "FILL(1)";
    op_copy.push_back(str);
    if (!vis[A][b_cup])
      que.push({A, b_cup, step + 1, op_copy}), vis[A][b_cup] = true;
    
    // 尝试fill B
    op_copy = p.op;
    str = "FILL(2)";
    op_copy.push_back(str);
    if (!vis[a_cup][B])
      que.push({a_cup, B, step + 1, op_copy}), vis[a_cup][B] = true;
    
    // 尝试drop A
    op_copy = p.op;
    str = "DROP(1)";
    op_copy.push_back(str);
    if (!vis[0][b_cup])
      que.push({0, b_cup, step + 1, op_copy}), vis[0][b_cup] = true;

    // 尝试drop B
    op_copy = p.op;
    str = "DROP(2)";
    op_copy.push_back(str);
    if (!vis[a_cup][0])
      que.push({a_cup, 0, step + 1, op_copy}), vis[a_cup][0] = true;
    
    // 尝试pour A -> B
    op_copy = p.op;
    str = "POUR(1,2)";
    op_copy.push_back(str);
    int a_cup_new, b_cup_new;
    if (a_cup + b_cup > B)
      a_cup_new = a_cup + b_cup - B, b_cup_new = B;
    else 
      a_cup_new = 0, b_cup_new = a_cup + b_cup;
    if (!vis[a_cup_new][b_cup_new])
      que.push({a_cup_new, b_cup_new, step + 1, op_copy}), vis[a_cup_new][b_cup_new] = true;

    // 尝试pour B -> A
    op_copy = p.op;
    str = "POUR(2,1)";
    op_copy.push_back(str);
    // int a_cup_new, b_cup_new;
    if (a_cup + b_cup > A)
      a_cup_new = A, b_cup_new = a_cup + b_cup - A;
    else 
      a_cup_new = a_cup + b_cup, b_cup_new = 0;
    if (!vis[a_cup_new][b_cup_new])
      que.push({a_cup_new, b_cup_new, step + 1, op_copy}), vis[a_cup_new][b_cup_new] = true;
  }
  return -1;
}
int main() {
  scanf("%d %d %d", &A, &B, &C);
  int ret = bfs({0, 0, 0, std::vector<std::string>{}});
  if (ret == -1) printf("impossible\n");
  else ans.decode(); 
  return 0;
}
