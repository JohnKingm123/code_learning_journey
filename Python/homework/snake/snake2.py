# -*- coding: utf-8 -*-
"""
Created on Sun Apr 24 12:41:53 2022

@author: JK
"""


import turtle as t
import random as r
t.setup(300,300,0,0)
t.pendown()
t.pensize(5)
t.pencolor('red')
#t.goto(100,200)
x0=0
y0=0
t.penup()
t.goto(x0,y0)
t.pendown()

arc=r.randint(-90,90)
print(arc)
t.seth(arc)
t.forward(20)
x1=t.pos()[0]
y1=t.pos()[1]
print(t.pos())

'''arc=r.randint(-90,90)
print(arc)
t.seth(arc)
t.forward(20)
x2=t.pos()[0]
y3=t.pos()[1]

arc=r.randint(-90,90)
print(arc)
t.seth(arc)
t.forward(20)
x3=t.pos()[0]
y3=t.pos()[1]
'''
for i in range(9):
    arc=r.randint(-90,90)
    print(arc)
    t.seth(arc)
    t.forward(20)

t.done()