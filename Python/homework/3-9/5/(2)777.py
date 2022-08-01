# -*- coding: utf-8 -*-
"""
Created on Sun Apr 24 11:27:06 2022

@author: JK
"""





import random
#初始化
Red_ball = [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33]
Blue_ball = [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16]

Reward_Num = ["","","","","",""]
Special_Num = [""]

Num_R = 0
Num_B = 0
i = 0
j = 0

def ran_shuffle(Num_ball):
    random.shuffle(Num_ball)
ran_shuffle(Red_ball)
ran_shuffle(Blue_ball)
print("33个红色球重新随机排序",Red_ball)
print("16个蓝色球重新随机排序",Blue_ball)


while j < 6:
    try:
        Num_R = random.randint(0, len(Red_ball)-1)
        print("随机数位：%d"%Num_R)
    except BaseException:
        print("随机数位报错：", Num_R)
    Reward_Num[j] = Red_ball[Num_R]
    print("红球号码：",Red_ball[Num_R])
    print(Reward_Num)
    del Red_ball[Num_R]

    print("第%d循环："%(j+1))
    print("数位:",Num_R)
    print("第%d次开球,开奖号码：%d"%(j+1,Reward_Num[j]))
    j += 1
print("本期红球中奖号码：%d",Reward_Num)
print("删除后的红球号码池：%d",Red_ball)
while i < 1:
    Num_B = random.randint(0, len(Blue_ball)-1)
    Special_Num[i] = Blue_ball[Num_B]
    # del Blue_ball[Num]

    print("第%d循环："%(i+1))
    print("数位:",Num_B)
    print("特殊号码：%d"%Special_Num[0])
    i += 1
    pass

print("本期中将号码为：",sorted(Reward_Num),Special_Num)
