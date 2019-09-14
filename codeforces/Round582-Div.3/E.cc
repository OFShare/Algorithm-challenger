//
// Created by OFShare on 2019-09-12
//

#include <bits/stdc++.h>

int n;
std::string s, t;

const std::string A[] = {"abc", "acb", "bac", "bca", "cab", "cba"};
char c[] = {'a', 'b', 'c'};
std::vector<std::string> vec;

int main() {
    std::cin >> n >> s >> t;
    // 构造几种串
    for(int i = 0; i < 6; ++i) {
        std::string str;
        for(int j = 1; j <= n; ++j) {
            str.append(A[i]);
        }
        vec.push_back(str);
    }
    do{
        std::string str;
        str.append(n, c[0]);
        str.append(n, c[1]);
        str.append(n, c[2]);
        vec.push_back(str);
    }while(std::next_permutation(c, c+3));

    for(const auto &str: vec) {
        // 如果构造的串没有包含s和t
        if(str.find(s) == std::string::npos && str.find(t) == std::string::npos) {
            std::cout << "YES" << std::endl;
            std::cout << str << std::endl;
            exit(0);
        }
    }
    return 0;
}
