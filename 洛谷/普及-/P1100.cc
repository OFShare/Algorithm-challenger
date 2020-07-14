#include <iostream>
#include <algorithm>
#include <string>
#include <bitset>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::sort;
using std::bitset;

int main(void) {
  unsigned long long n = 0;
  cin >> n;

  bitset<32> binary(n),rev(0);

  for (int i = 0; i < 16; i++)
  {
    rev[16+i] = binary[i];
  }

  for (int i = 0; i < 16; i++)
  {
    rev[i] = binary[i + 16];
  }

  cout << rev.to_ullong() << endl;
  return 0;
}
