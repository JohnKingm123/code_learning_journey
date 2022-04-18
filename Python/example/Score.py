# -*- coding: utf-8 -*-
"""
Created on Tue Apr 12 13:07:58 2022

@author: JK
"""

age,height,weight,skill,hardware=38,1.8,147,120,290
condition=[age<35,height>1.7,100<weight<150,skill>100,hardware>300]
result=('NO','YES')[all(condition)]'''sum也可'''
print(result)