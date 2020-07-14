/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-03-15 21:10:17 PM
 * File Name     : P1125.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int INF = 1e9;
const int N = 1e2 + 5;
char word[N];
std::map<char, int> mp;

// 判断是否是素数
bool prime(int x) {
  if (x == 0 || x == 1) return false;
  for (int i = 2; i * i <= x; ++i) {
    if (x % i == 0) return false;
  }
  return true;
}
int main() {
  scanf("%s", word + 1);
  for (int i = 1; i <= std::strlen(word + 1); ++i) {
    mp[word[i]]++;
  }
  int max_word = 0, min_word = INF;
  for (auto it = mp.begin(); it != mp.end(); ++it) {
    max_word = std::max(max_word, it -> second);
    min_word = std::min(min_word, it -> second);
  }
  if (prime(max_word - min_word)) printf("Lucky Word\n"), printf("%d\n", max_word - min_word);
  else printf("No Answer\n"), printf("0\n");
  return 0;
}
