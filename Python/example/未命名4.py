# -*- coding: utf-8 -*-
"""
Created on Wed Apr 13 11:22:32 2022

@author: JK
"""

m,n=input().split(',')
m=int(m)
n=int(n)
c="Catalytic pyrolysis of heavy oils on various catalysts was investigated in a confined fluidized bed reactor"
ls=[]
ls=c.split()
for i in range(m,n):
    ls.remove(ls[m])
print(ls)
