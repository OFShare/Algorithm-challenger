### 字符串常见基本算法

- **Hash**

  字符串hash的原理其实非常简单, 对于123456, 如何我们想取它的字串3456, 就是: 3456 = 123456 - 12 * 10 ^ 4. 这是在10进制下对于整数的处理. 我们采用类比的方式思考, 对于字符串abcdef, 如果我们想取它的子串def, 就是: def = abcdef - abc * base ^ 3.

  这就是我们常说的**进制hash** 或 **多项式hash**

  ```c++
  struct Hash {
    typedef unsigned long long ull;
    static const int maxn = 1e6 + 5;
    // 31 131 1313 13131 131313 etc..
    static const int base = 1e9 + 7;
    char str[maxn];
    ull h[maxn], p[maxn];
  
    void init() {
      h[0] = 0;
      p[0] = 1;
      int len = strlen(str + 1);
      for (int i = 1; i <= len; ++i) {
        h[i] = h[i - 1] * base + str[i];
        p[i] = p[i - 1] * base;
      }
    }
  
    ull get(int L, int R) {
      return h[R] - h[L - 1] * p[R - L + 1];
    }
  }hash;
  ```

  [模板例题UVA-10298](https://vjudge.net/problem/UVA-10298), [模板代码](./UVA-10298.cc). 

  参考: https://zhuanlan.zhihu.com/p/78418415

- **字典树**

  字典树**用边来**代表字母, 而从根结点到树上某一结点的路径就代表了一个字符串.

  ```c++
  struct trie {
    int nex[100000][26], cnt;
    bool exist[100000];  // 该结点结尾的字符串是否存在
  
    void insert(char *s, int l) {  // 插入字符串
      int p = 0;
      for (int i = 0; i < l; i++) {
        int c = s[i] - 'a';
        if (!nex[p][c]) nex[p][c] = ++cnt;  // 如果没有，就添加结点
        p = nex[p][c];
      }
      exist[p] = 1;
    }
    bool find(char *s, int l) {  // 查找字符串
      int p = 0;
      for (int i = 0; i < l; i++) {
        int c = s[i] - 'a';
        if (!nex[p][c]) return 0;
        p = nex[p][c];
      }
      return exist[p];
    }
  };
  ```

  [模板例题HDU-1251](https://vjudge.net/problem/HDU-1251), [模板代码](./HDU-1251.cc)

  参考: https://oi-wiki.org/string/trie/

- **KMP**

  ```c++
  // fail[i]:  表示(0 ~ i -1)前缀和后缀的最大的公共长度
  // "ababcd": fail数组: 0, 0, 0, 1, 2, 0, 0
  void getFail(const char *p, int len) {
    fail[0] = fail[1] = 0;
    // 用fail[i]的状态去更新fail[i + 1]状态
    for (int i = 1; i < len; ++i) {
      int j = fail[i];
      if (p[j] == p[i]) 
        fail[i + 1] = j + 1;
      else {
        while (j && p[j] != p[i])
          j = fail[j];
        if (p[j] == p[i])
          fail[i + 1] = j + 1;
        else 
          fail[i + 1] = 0;
      }
    }	
  }
  
  // 遍历一遍
  for (int i = 0; i < len; ++i) {
    while (j && text[i] != pattern[j]) 
      j = fail[j];
    if (text[i] == pattern[j]) {
      ++j;
      if (j == len_pattern) {
        ++ret;
        j = fail[j];
      }
    }   
  }
  
  ```

  [模板例题HDU-1686](https://vjudge.net/problem/HDU-1686)， [模板代码](./HDU-1686.cc)

  参考: https://blog.csdn.net/ck_boss/article/details/47066727

- **AC自动机**

  ```c++
  namespace AC {
  int tr[N][26], tot;
  int e[N], fail[N];
  void insert(char *s) {
    int u = 0;
    for (int i = 1; s[i]; i++) {
      if (!tr[u][s[i] - 'a']) tr[u][s[i] - 'a'] = ++tot;
      u = tr[u][s[i] - 'a'];
    }
    e[u]++;
  }
  queue<int> q;
  void build() {
    for (int i = 0; i < 26; i++)
      if (tr[0][i]) q.push(tr[0][i]);
    while (q.size()) {
      int u = q.front();
      q.pop();
      for (int i = 0; i < 26; i++) {
        if (tr[u][i])
          fail[tr[u][i]] = tr[fail[u]][i], q.push(tr[u][i]);
        else
          tr[u][i] = tr[fail[u]][i];
      }
    }
  }
  int query(char *t) {
    int u = 0, res = 0;
    for (int i = 1; t[i]; i++) {
      u = tr[u][t[i] - 'a'];  // 转移
      for (int j = u; j && e[j] != -1; j = fail[j]) {
        res += e[j], e[j] = -1;
      }
    }
    return res;
  }
  }  // namespace AC
  ```

  参考: https://oi-wiki.org/string/ac-automaton/

  参考: https://www.cnblogs.com/zzqsblog/p/6227545.html, AC自动机**建fail树**

- **manacher**

- **后缀数组**

- **EXKMP**

- **SAM后缀自动机**

- **回文串自动机**

---

1. [HDU-4821](https://vjudge.net/problem/HDU-4821), [参考AC代码](./HDU-4821-hash.cc)

   hash + 滑动窗口优化

2. [UVA-10298](https://vjudge.net/problem/UVA-10298), [参考AC代码](./UVA-10298.cc)

   hash

3. [UVA-11475](https://vjudge.net/problem/UVA-11475), [参考AC代码](./UVA-11475.cc)

   hash求最长回文后缀

4. [P3370](https://www.luogu.com.cn/problem/P3370), [参考AC代码](./P3370-hash.cc)

   入门hash

5. [SP7586](https://www.luogu.com.cn/problem/SP7586), [参考AC代码](./SP7586.cc)

   求一个串中包含几个回文串. std标准做法是manacher, 也可以hash + 枚举长度, 其中枚举长度可以二分.

   ---

   小结: 字符串的很多特性是具有**单调性**的, 二分求解是一个常见的思路, 配合哈希进行判断操作一般可以做到在 O(nlongn效率内完成问题

6. [HDU-1251](https://vjudge.net/problem/HDU-1251), [参考AC代码](./HDU-1251.cc)

   字典树

7. [POJ-3630](https://vjudge.net/problem/POJ-3630), [参考AC代码](./POJ-3630.cc)

   字典树, 注意题目的数据范围标错了, 应该是1e5,

8. [HDU-1686](https://vjudge.net/problem/HDU-1686), [参考AC代码](./HDU-1686.cc)

   kmp

9. [P3808](https://www.luogu.com.cn/problem/P3808), [参考AC代码](./P3808.cc)

   AC自动机简单版本

10. [P3796](https://www.luogu.com.cn/problem/P3796), [参考AC代码](./P3796.cc)

    AC自动机加强版本, 在fail指针上暴力跳边

11. [P5357](https://www.luogu.com.cn/problem/P5357), [参考AC代码](./P5357.cc)

    如果在fail指针上暴力跳边, 则会T. [参考tle代码](./P5357-tle.cc)

    我们需要优化, 通过建立**fail树优化**

    fail树其实很好理解, 在trie图上, x会跳向fail[x], fail[x]也会接着向上跳, 直到根节点. 我们返过来看, 从根节点到x节点是不是构成了树的一条边. 这样就可以建立唯一的fail树了. 代码里fail树是用**链式前向星**建立的.

12. 