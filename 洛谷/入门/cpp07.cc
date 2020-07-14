/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-05-24 11:50:59 AM
 * File Name     : cpp07.cc
 */

#include <bits/stdc++.h>

using namespace std;

#define ll long long
void debug() {
#ifdef Acui
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
}

class Connection {
  public:
    explicit Connection(string name):_name(name) {
    }
    string get_name() const {
      return _name;
    }
  private:
    string _name;
};

void close(Connection* connection) {
  cout << string("关闭") + connection->get_name() + "管理的连接中..." << endl;
  //关闭连接的代码
  // .....
  cout << "关闭完成。" << endl;
}

int main() {
  auto Deleter = [](Connection *connection) {
    std::cout << "custom deleter" << std::endl;
    delete connection;
  };

  // 新建管理连接Connection的智能指针
  {
    shared_ptr<Connection> sp(new Connection("123"), Deleter);
    unique_ptr<Connection> up(new Connection("456"));
  }
}
