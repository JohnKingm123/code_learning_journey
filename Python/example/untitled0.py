# -*- coding: utf-8 -*-
"""
Created on Tue Apr 12 13:06:26 2022

@author: JK
"""

score=int(input())
deg='EEEEEEDCBAA'
if(score>100 or score<0):
    print("Not valid")
else:
    print(deg[score//10]) 