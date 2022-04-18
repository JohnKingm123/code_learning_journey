# -*- coding: utf-8 -*-
"""
Created on Wed Apr 13 10:59:41 2022

@author: JK
"""

n=input()
n=int(n)
for i in range(0,n,7):
    if (i%3==2 and i%5==1):
        print(i,end=(' '))