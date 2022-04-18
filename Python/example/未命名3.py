# -*- coding: utf-8 -*-
"""
Created on Wed Apr 13 11:17:59 2022

@author: JK
"""

import random
n=input
n=int(n)
random.seed(n)
m=random.randint(1, n)
ls=[]
for i in range(1,n+1):
    ls.append(i)
print(ls)
for i in range(1,n+1):
    if(i%m==0):
        ls.remove(i)
print(ls)