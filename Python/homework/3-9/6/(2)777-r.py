# -*- coding: utf-8 -*-
"""
Created on Sun Apr 24 11:27:06 2022

@author: JK
"""





import random
#初始化


Reward_Num = ["","","","","",""]
Special_Num = [""]

cot=0
key = ["1","2","3","4","6","11"]#中将号码


def ran_shuffle(Num_ball):
    random.shuffle(Num_ball)
    return 0



def ch():
    Num_R = 0
    Num_B = 0
    i = 0
    j = 0
    Red_ball = [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33]
    Blue_ball = [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16]
    ran_shuffle(Red_ball)
    ran_shuffle(Blue_ball)

    while j < 6:
        try:
            Num_R = random.randint(0, len(Red_ball)-1)
        except BaseException:
            print("随机数位报错：", Num_R)
        Reward_Num[j] = Red_ball[Num_R]
        
        del Red_ball[Num_R]

        
        j += 1

    while i < 1:
        Num_B = random.randint(0, len(Blue_ball)-1)
        Special_Num[i] = Blue_ball[Num_B]
        # del Blue_ball[Num]

       
        i += 1
        pass

    print("本次选中号码为：",sorted(Reward_Num),Special_Num)
    return Reward_Num

while (key!=ch()):
    cot=cot+1


rate=1/cot
print(cot) 
print(rate)