score=int(input(""))

if(score<0 or score>100):
    print("Not valid")
elif(score>=90):
    print('优')
elif(score>=80):
    print('良')
elif(score>=70):
    print('中')
elif(score>=60):
    print('及格')
else :print('不及格') 
