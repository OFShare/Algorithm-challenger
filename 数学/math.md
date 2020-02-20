##### 数学相关

没有数学就没有算法;

没有好的数学基础,也很难在算法上有所成就。

竞赛中涉及的常见数学概念和方法,包括数论、排列组合、递推关系和离散概率等。

这里推荐我认为讲的不错的一些视频资料

1. [初等数论](https://www.bilibili.com/video/av23752897/), 内容是高中选修的初等数论初步, 很适合刚刚接触数论的萌新(QAQ)

2. [抽象代数](https://www.bilibili.com/video/av22685954), 了解群的概念, 可惜up主不更了.

3. [算法竞赛之数学基础](https://www.bilibili.com/video/av71378144?p=1)

4. [组合数学](https://www.bilibili.com/video/av22736338?p=23), 熟悉常见的排列组合, 更有母函数清晰的讲解

   ---

1. `同余性质`

   传递性:

   ​             a ≡ b (mod m), b ≡ c (mod m)

   ​       则, a ≡ c (mod m)

   线性运算:

   ​             a ≡ b (mod m)

   ​             c ≡ d (mod m)

   ​       则, a ± c ≡ b ± d (mod m) 

   ​             a * c ≡ b * d (mod m)

   除法:

   ​             a * c ≡ b * c (mod m) c≠0

   ​       则, a ≡ b (mod m / gcd(c,m))  

   ​       若c和m互素, a ≡ b (mod m)

   幂运算:

   ​          	a ≡ b (mod m)

   ​        则, a ^ n ≡ b ^ n (mod m)

   另外两个常见的:

   ​        若a ≡ b (mod m)，n|m,则 a ≡ b (mod n) 

   ​        若a ≡ b (mod mi) (i=1,2…n) 则 a ≡ b (mod [m1,m2,…mn]) 其中[m1,m2,…mn]表示m1,m2,…mn的最小公倍数

2. `欧几里得和扩展欧几里得的证明`

   proof: gcd(a, b) == gcd(b, a % b)

   我们只要推出这三个整除就很好证明了`d |a`, `d | b`, `d | a % b`

   设a和b的公约数为d, 数学符号记为d = (a, b).

   所以d | a, d | b

   a = d * k1        (1)

   b = d * k2        (2)

   设a ÷ b = p ... q

   由(1)式得: p * b + q = d * k1, 然后将(2)式代入得:

   p * (d * k2) + q = d * k1, 整理一下得

   q = d * k1 - p * d * k2 = d * (k1 - p * k2)

   即 d | q, d | (a % b).

   这里我们就推出了`d |a`, `d | b`, `d | a % b`

   因为d | a, d | b, 所以d = (a, b)

   因为d | b, d | (a % b), 所以d = (b, a % b)

   (a, b) == (b, a % b), 即它们的公约数一样, 当然最大公约数也是一样的, 得证.

   ```c++
   // 递归函数的作用是返回a, b的最大公约数
   int gcd(int a, int b) {
   	return b == 0? a: gcd(b, a % b);
   }
   ```

   ---

   扩展欧几里得

   a * x + b * y = gcd(a, b), 对于这个式子, 可能很多人只会背它的模板, 其实它的推导是很简单的, 我这里简单推一下.

   因为: 

   a * x + b * y = gcd(a, b) = d 即对于输入的a, b, 可以算出对应的x, y和d. 

   那么我们输入是b, a % b时, 也是可以的, 那么上式就变成这样

   b * x1 + (a % b) * y1 = gcd(b, a % b) = d1

   因为gcd(a, b) = gcd(b, a % b), 所以d = d1, 所以

   a * x + b * y = b * x1 + (a % b) * y1, 整理一下得:

   a * x + b * y = a * y1 + b * (x1 - (a / b) * y1), 根据对应项相等:

   x = y1

   y = x1 - (a / b) * y1

   接下来我们下代码就简单了:

   ```c++
   // ax + by = gcd(a, b) = d
   // 递归函数输入a, b算出: d, x, y
   void exgcd(long long a, long long b, long long &d, long long &x, long long &y) {
   	if (b == 0) {
           d = a;
           x = 1;
           y = 0;
           return ;
       }
       int x1, y1;
       exgcd(b, a % b, d, x1, y1);
       d = d;
       x = y1;
       y = x1 -(a / b) * y1;
   }
   ```

对于扩展欧几里得的题目, 经常会要我们求**最小正整数解**, 下面我们也来推一下

   ax + by = gcd(a, b) = d.

   根据扩展欧几里得, 我们求出上面等式的一组特解(x1, y1), 即:

   a * x1 + b * y1 = d, 这里简单恒等变换一下:

   a * (x1 + b * k) + b * (y1 - a * k) = d, k是任意整数

   所以x1 + b * k是它的通解, 所以最小正整数解为:

   `((x1 + b * k) % b + b ) % b`. 这个式子可能看上去很懵? 其实很简单, 首先如果x1含有b的因子, 那么它可以放到b * k中去, 这样我们可以假设x1是最简化的形式且是个正数, 那么我们k取0就行了, 而这和模b是一样的.后面的加b再取模, 只是防止负数的情况. 因为虽然数学上定义的是 一个数模b, 应该等于0 ~ (b - `), 但是在编程语言的实现中取可以是个负数, 这个负数其实是在一个等价类里, 我们 加b再%b, 可以保证答案是大于等于0的数.

所以当我们求出特解x1时, 那么最小的正整数就是((x1 % b) + b) % b, x1是通解的一个表示.

3. `费马小定理`

   a ^ p ≡ a (mod p), p是一个素数

   如果a和p互素, 根据同余的除法性质, 则:

   a ^ (p - 1) ≡ 1 (mod p), 这个公式可以很好的求逆元:

   a * a ^ (p - 2) ≡ 1 (mod p), 则a和a ^ (p - 2)互为逆元

4. `中国剩余定理(孙子定理)`

   x ≡ a1 (mod m1)

   x ≡ a2 (mod m2)

   x ≡ a3 (mod m3)

   ​       .

   ​       .

   ​       .

   x ≡ ak (mod mk)

   m1, m2, m3, ..., mk两两互素, M = m1 * m2 * m3 * ... * mk

   我们可以构造解:

   X = (a1 * M1 * y1 + a2 * M2 * y2 + ... + ak * Mk * yk) % M

   其中: Mi * yi ≡ 1 (mod mi), Mi = M / mi

   当我们求得X为同余方程的解时, 即满足上面的所有约束条件, 那么显然:

   X + M, X + 2 * M, X + k * M 都是解, 那么**最小的大于等于零解**, 就是:

   (X % M + M) % M

   这里说点题外话: **一个数取模, 如a % b, 类似于做减法, 把a里面所有包含b的倍数的数给减去, 所以要求最小的>=0的整数, 就是(a % b + b) % b**

   最后, 因为这是k个方程, 我们可以暴力的枚举每个x, 然后看它是否符合约束. 这里有个优化, x可以跳着加.

5. `欧拉定理`

   ​    a ^ φ(n) ≡ 1 (mod n), 正整数a, n互质

   φ(n) 是欧拉函数: 小于或等于n的正整数中与n[互质](https://baike.baidu.com/item/互质/577412)的数的数目, φ(1) = 1

   通式：

   ![img](https://gss0.bdstatic.com/-4o3dSag_xI4khGkpoWK1HF6hhy/baike/pic/item/f3d3572c11dfa9ecf6f6c0dd68d0f703908fc124.jpg)

    (其中p1, p2……pn为x的所有质因数，x是不为0的整数)

6. 

