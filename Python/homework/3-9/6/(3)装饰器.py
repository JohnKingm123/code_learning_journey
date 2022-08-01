import time
def time_cost (func):
    def wrapper(*args,**kw):
        start=time.time()
        func(*args,**kw)
        print(f'函数名:{func.__name__},运行时间：{time.time()-start}')
    return wrapper


def h():
    print("helloworld")


@time_cost
def h():
    for i in range(65535):
    
        print("helloworld")
    return 0

a=h()