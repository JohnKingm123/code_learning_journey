# -*- coding: utf-8 -*-
"""
Created on Wed Apr 13 09:50:50 2022

@author: JK
"""

ls = ['2', '3', '0', '1', '5']
s=input()
i=int(input())
ls.append(s)
if (i<0):
    ls.append(s)
else:
    ls.insert(i, s)