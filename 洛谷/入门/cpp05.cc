/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-05-21 18:43:37 PM
 * File Name     : cpp05.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

class Base {
  public:
    Base() {
      std::cout << "ctor base" << std::endl;
    }
    virtual ~Base() {
      std::cout << "dtor base" << std::endl;
    }
};

class Derived: public Base {
  public:
    Derived() {
      std::cout << "ctor derived" << std::endl;
    }
    virtual ~Derived() {
      std::cout << "dtor derived" << std::endl;
    }
};

Derived* factory() {
  return new Derived();
}
int main() {
  Derived* b = factory();
  delete b;

  std::cout << "======" << std::endl;
  return 0;
}
