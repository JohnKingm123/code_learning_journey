import random
import sys
def ra():
    while True:
        a=random.randint(0, 32767)
        yield  a


r=ra()

for i in range(0,10):
    a=r.__next__()
    print(a)