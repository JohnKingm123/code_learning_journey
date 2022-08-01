# -*- coding: utf-8 -*-
"""
Created on Tue Apr 19 13:35:17 2022

@author: JK
"""
str = str(input())
dict={}
for i in str :
    dict[i]=dict.get(i,0)+1

t=max(dict.values())

for m,n in dict.items():
    if n == t:
        print('m',n)