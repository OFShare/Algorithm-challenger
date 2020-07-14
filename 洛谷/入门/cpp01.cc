/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-05-21 00:48:23 AM
 * File Name     : cpp01.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

class Text {
  public:
    explicit Text(char *p) {
      text = p;
    }
    Text(const Text& rhs);
    Text& operator=(const Text& rhs);

    const char& operator[](std::size_t pos) const {
      std::cout << "do const" << std::endl;
      return text[pos];
    }
    char& operator[](std::size_t pos) {
      std::cout << "non-const" << std::endl;
      return const_cast<char&>(static_cast<const Text&>(*this)[pos]);
    }
  private:
    char *text;
};

int main() {
  char *p = "text";
  Text obj(p);
  std::cout << obj[2] << std::endl;

  return 0;
}
