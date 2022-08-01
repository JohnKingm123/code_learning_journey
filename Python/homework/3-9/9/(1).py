import jieba
import wordcloud
import imageio

content = open ("./source.txt","r",encoding="utf-8").read()

words = {}



def fun1():
    f1 = open("./dao.txt","w",encoding="utf-8")
    for word in content :
        words[word] = words.get(word,0)+1
        if word == '道':
            f1.write(word+'('+str(words[word])+')')
        else :
            f1.write(word)
            
    print(words)
    
    
    return
    
def fun2():
    
    wdict={}
    list1=jieba.lcut(content)
    for item in list1:
        if len(item)<2:
            continue
        wdict[item] = wdict.get(item,0)+1
    print(wdict)
    
    
    return wdict
    
def fun3():
    dic=fun2()
    string = ''.join(dic)
    mk = imageio.imread("OIP-C.jpg")
    w= wordcloud.WordCloud(width=600,height=300,
    background_color='white',font_path='./msyh.TTC',
    contour_width=1,contour_color='steelblue',mask=mk)
    w.generate(string)
    w.to_file('result2.jpg')
    
    
    
    
    return
    
    
    
if __name__=='__main__':
    #a=fun1()
    b=fun2()
    #c=fun3()
    print("done")