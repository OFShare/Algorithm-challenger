//
// Created by OFShare on 2019-09-14
//

#include <bits/stdc++.h>

int q, n;
std::vector<int > vec(404);

int main() {
    scanf("%d", &q);
    while(q--) {
        vec.clear();
        scanf("%d", &n);
        for(int i = 1; i <= 4 * n; ++i) {
            scanf("%d", &vec[i]);
        }
        std::sort(vec.begin() + 1, vec.begin() + 1 + 4 * n);
        // 最短的两条边和最长的两条边组合, 次短的两条边和次最长的两条边组合，依次类推
        int L = 1, R = 4 * n, remain = n;
        int area = -1;
        bool is_ok = true;
        while(remain--) {
            std::vector<int > tmp_4edges;
            tmp_4edges.push_back(vec[L++]);
            tmp_4edges.push_back(vec[L++]);
            tmp_4edges.push_back(vec[R--]);
            tmp_4edges.push_back(vec[R--]);
            std::sort(tmp_4edges.begin(), tmp_4edges.end());
            if(!(tmp_4edges[0] == tmp_4edges[1] && tmp_4edges[2] == tmp_4edges[3])){
                is_ok = false;
                break;
            }
            if(area == -1)
                area = tmp_4edges[0] * tmp_4edges[3];
            else
                is_ok = (area == tmp_4edges[0] * tmp_4edges[3]? true: false);
            if(!is_ok)
                break;
        }
        if(is_ok)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
