/*
 * Created by OFShare on 2020-01-28, 春节期间
 *
 */ 

#include <cstdio>
#include <cstring>

const int maxn = 1e6 + 5;

int t;
char pattern[maxn], text[maxn];

int fail[maxn];

// fail[i]:  表示(0 ~ i -1)前缀和后缀的最大的公共长度
// "ababcd": fail数组: 0, 0, 0, 1, 2, 0, 0
void getFail(const char *p, int len) {
  fail[0] = fail[1] = 0;
  // 用fail[i]的状态去更新fail[i + 1]状态
  for (int i = 1; i < len; ++i) {
    int j = fail[i];
    if (p[j] == p[i]) 
      fail[i + 1] = j + 1;
    else {
      while (j && p[j] != p[i])
        j = fail[j];
      if (p[j] == p[i])
        fail[i + 1] = j + 1;
      else 
        fail[i + 1] = 0;
    }
  }	
}

int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%s %s", pattern, text);
    getFail(pattern, strlen(pattern));

    int j = 0;
    int len = strlen(text), ret = 0;
    int len_pattern = strlen(pattern);

    // 遍历一遍
    for (int i = 0; i < len; ++i) {
      while (j && text[i] != pattern[j]) 
        j = fail[j];
      if (text[i] == pattern[j]) {
        ++j;
        if (j == len_pattern) {
          ++ret;
          j = fail[j];
        }
      }		
    }
    printf("%d\n", ret);
  }
  return 0;
}
