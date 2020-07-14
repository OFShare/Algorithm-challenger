/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-06-09 22:21:18 PM
 * File Name     : cpp12.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

std::map<std::string, std::string> g_pages;
int sum = 0;
std::mutex g_pages_mutex;
 
void save_page(const std::string &url)
{
    for (int i = 1; i <= 1000000; ++i) {
      ++sum;
    }
    // 模拟长页面读取
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::string result = "fake content" + url;
    
    std::cout << url << " :" << result << std::endl;
    // std::lock_guard<std::mutex> guard(g_pages_mutex);
    g_pages[url] = result;
}
 
int main() 
{
    std::thread t1(save_page, "http://foo");
    std::thread t2(save_page, "http://bar");

    std::this_thread::sleep_for(std::chrono::seconds(200));
    std::cout << "start t1.join()" << std::endl;
    t1.join();
    t2.join();
    
    std::cout << "sum: " << sum << std::endl;
    // 现在访问g_pages是安全的，因为线程t1/t2生命周期已结束
    for (const auto &pair : g_pages) {
        std::cout << pair.first << " => " << pair.second << '\n';
    }
}
