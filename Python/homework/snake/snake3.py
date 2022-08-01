# -*- coding: utf-8 -*-
"""
Created on Sun Apr 24 12:58:04 2022

@author: JK
"""

import turtle as t
import random as r

t.speed(1)
t.setup(600,600,0,0)
t.pendown()
t.pensize(5)
t.pencolor('red')
#t.goto(100,200)
x0=0
y0=0
t.penup()
t.goto(x0,y0)
t.pendown()

snake_body=[]
snake_body.append(list(t.pos()))

arc=r.randint(-90,90)
t.seth(arc)
t.forward(90)
x1=t.pos()[0]
y1=t.pos()[1]
print(t.pos())
snake_body.append(list(t.pos()))
#第一步
'''print(t.pos())

arc=r.randint(-90,90)
print(arc)
t.seth(arc)
t.forward(20)
x2=t.pos()[0]
y2=t.pos()[1]

arc=r.randint(-90,90)
print(arc)
t.seth(arc)
t.forward(20)
x3=t.pos()[0]
y3=t.pos()[1]
'''
for i in range(2,20):
    arc=r.randint(-90,90)
    t.seth(arc)
    t.forward(90)
    snake_body.append(list(t.pos()))
    print(snake_body)
    #前进
    t.penup()
    t.goto(snake_body[i-2])
    t.pendown()
    t.pencolor('white')
    t.goto(snake_body[i-1])
    
    t.penup()
    t.goto(snake_body[i])
    t.pendown()
    t.pencolor('red')
    
    
    
t.done()