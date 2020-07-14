/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-05-23 22:59:16 PM
 * File Name     : cpp06.cc
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
    Widget(const int &a): a_(a) {
      std::cout << "ctor" << std::endl;
    }
  public:
    ~Widget() {
      std::cout << "dctor" << std::endl;
    }
  public:
    int a_;
};

Widget* get_factory() {
  return new Widget(1);
}

int main() {
  Widget* p = get_factory();
  delete p;
  std::cout << "========" << std::endl;

  {
    std::shared_ptr<Widget> w(get_factory()); // RAII
  }
  return 0;
}
