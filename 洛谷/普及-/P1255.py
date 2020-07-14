# -*- coding:utf-8 -*-

#开数组，更简单
farr =[]
import sys
#输入
n=int(input())
#注意到如果没有台阶就输出0，在这里WA了一次
if n==0:
    print (0)
    sys.exit()
#经典的肥波纳妾数列过程
for i in range(n+1):
    if i ==0 or i ==1:
        farr.append(1)
    else:
        farr.append(farr[i-2]+farr[i-1])
#数列最后一项即为答案
print(farr[n])
#结束
