# -*- coding: utf-8 -*-
"""
Created on Wed Apr 13 09:57:43 2022

@author: JK
"""

a,n=input().split(' ')

n=int(n)
su=''
re=''
for i in range(0,n):
    su=su+a

v_su=eval(su)
for i in range(0,n-1):
    re=re+a
    v_su=v_su-eval(re)
    
print(v_su)