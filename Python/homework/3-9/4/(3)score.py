import random
list1=[]
list2=[]
xing='赵钱孙李周吴郑王'
ming='如玉元德华建刚一山'
name1=random.choice(xing)+"".join(random.choices(ming,k=random.randint(1, 2)))
name2=random.choice(xing)+"".join(random.choices(ming,k=random.randint(1, 2)))
name3=random.choice(xing)+"".join(random.choices(ming,k=random.randint(1, 2)))

list1.append(name1)
list1.append(name2)
list1.append(name3)

list2.append(random.uniform(0, 100))
list2.append(random.uniform(0, 100))
list2.append(random.uniform(0, 100))

c=dict(zip(list1,list2))
print(c)