# -*- coding: utf-8 -*-
"""
Created on Tue Apr 19 13:27:01 2022

@author: JK
"""

try:
    f = open('./kkk.txt', 'r')
    print(*f.read(),sep='$')
except:
     print('sorry')
finally:
     print('不管咋样，我始终执行') 