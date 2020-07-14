/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-05-21 18:17:53 PM
 * File Name     : cpp04.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

template<class T>
class Widget {
  public:
    Widget(std::string& name, const T& value): name_(name), value_(value) {

    }
  private:
    std::string& name_;
    const T value_;
};

int main() {
  std::string s("abc");
  Widget<int> w1(s, 5);
  Widget<int> w2(s, 5);
  w2 = w1;
  return 0;
}
