# -*- coding: utf-8 -*-
"""
Created on Tue Apr 12 13:27:57 2022

@author: JK
"""

import time
#计算时间函数  
def show_run_time(func):
    def wrapper(*args, **kw):  
        start_time = time.time()
        func(*args, **kw) 
        print (f'函数名： {func.__name__} 运行时间： {time.time() - start_time}')
    return wrapper