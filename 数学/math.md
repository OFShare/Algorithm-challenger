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

1. `欧几里得和扩展欧几里得的证明`

   proof: gcd(a, b) == gcd(b, a % b)

   我们只要推出这三个整除就很好证明了`d |a`, `d | b`, `d | a % b`

   设a和b的公约数为d, 数学符号记为d = (a, b).

   所以d | a, d | b

   a = d * k1        (1)

   b = d * k2        (2)

   即a ÷ b = p ... q

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

   a * x + b * y = gcd(a, b), 对于这个式子, 可能很多人只会背它的模板, 其实它的推导是很简单的, 我这里简单证一下.

   因为: 

   a * x + b * y = gcd(a, b) = d 即对于输入的a, b, 可以算出对应的x, y和d. 

   那么我们输入是(b, a % b)时, 也是可以的, 那么上式就变成这样

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

   
