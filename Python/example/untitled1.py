# -*- coding: utf-8 -*-
"""
Created on Wed Apr  6 15:29:51 2022

@author: JK
"""

"""
【问题描述】拿一张报纸，对折，再对折，继续对折，我们对折叠后的总厚度感兴趣。要求给出一个折叠次数范围，比如折叠三到六次，编程序依次输出3、4、5、6次折叠后厚度（以米为单位）。一张纸的厚度大约是1/200厘米。
【输入形式】对折次数范围

【输出格式】输出分为两部分，第一行是折纸次数n以及相应高度height，使用语句print("n"+" "+"height")

其他行输出折叠次数以及高度，使用语句print(str( count )+" "+str( gaodu )+"m")，这里的count和gaodu分别代表折纸次数以及相应高度的变量。
"""
a=int(input())
b=int(input())
print("n"+" "+"height")
while (a<=b):
    th=2**a*1/20000
    print(str(a)+" "+str(th)+"m")
    a=a+1