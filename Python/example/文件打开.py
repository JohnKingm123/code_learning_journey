# -*- coding: utf-8 -*-
"""
Created on Tue Apr 19 13:18:50 2022

@author: JK
"""

f=[print,len,all,any,max]
import sys
old_out=sys.stdout
sys.stdout=open('./meme.txt','w')
for i in f:
    help(i)
sys.stdout.close() 
