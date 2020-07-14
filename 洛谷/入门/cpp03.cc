/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-05-21 01:03:00 AM
 * File Name     : cpp03.cc
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
    std::string s_;
    Widget() {
      std::cout << "Widget" << std::endl;
    }
};

class Singleton {
  public:
    Singleton() {
      std::cout << "singleton" << std::endl;
      a_ = 10;
      b_ = 11;
    }
  public:
    void print() {
      std::cout << "a_: " << a_ << std::endl;
      std::cout << "b_: " << b_ << std::endl;
    }
    void change() {
      a_ = 100;
      b_ = 111;
    }
  private:
    int a_;
    int b_;
    Widget w_;
};

Singleton& single() {
  static Singleton obj;
  return obj;
}

int main() {
  Singleton &obj = single();
  obj.print();
  obj.change();
  obj.print();

  std::cout << "=================\n";
  Singleton &obj2 = single();
  obj2.print();
  return 0;
}
