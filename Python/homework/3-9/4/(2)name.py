import random
list1=[]
xing='赵钱孙李周吴郑王'
ming='如玉元德华建刚一山'
name1=random.choice(xing)+"".join(random.choices(ming,k=random.randint(1, 2)))
print(name1)
