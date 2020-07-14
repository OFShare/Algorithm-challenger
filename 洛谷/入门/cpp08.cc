/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-05-24 12:28:13 PM
 * File Name     : cpp08.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

class Person {
  public:
    Person() {
      std::cout << "person" << std::endl;
    }
  private:
    std::string name_;
};

class Student: public Person {
  public:
    Student() {
      std::cout << "student" << std::endl;
    }
  private:
    std::string schoolName_;
};

int main() {
  Student s;
  return 0;
}
