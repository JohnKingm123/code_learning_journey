a = int(input())
pub_key=int(10)
b=a^pub_key

print("加密"+str(b))
print("解密"+str((b^pub_key)))