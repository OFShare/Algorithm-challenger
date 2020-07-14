/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-05-21 00:48:31 AM
 * File Name     : cpp02.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

class Widget {
  public:
    Widget() {
      std::cout << "ctorrrrrr" << std::endl;
    }
    Widget(int a, int b) {
      std::cout << "ctor1" << std::endl;
      a_ = a;
      b_ = b;
    }
    void print() {
      std::cout << "a: " << a_ << std::endl;
      std::cout << "b: " << b_ << std::endl;
    }
  private:
    int a_;
    int b_;
    std::string s_;
};

int main() {
  Widget w(10, 12);
  w.print();

  return 0;
}
