# -*- coding: utf-8 -*-
"""
Created on Sun Apr 24 13:17:15 2022

@author: JK
"""
'''
from requests_html import HTMLSession
session = HTMLSession()
url = "https://www.baidu.com/"
fileName = 'd:/trash/a.html'
with session.get(url) as r ,open(fileName,'w',encoding = 'utf-8') as f:
    f.write(r.text)
#     print(r.text) 
'''
'''
from requests_html import HTMLSession
session = HTMLSession()
r = session.post("http://www.shnu.edu.cn/")
# print(r.html.links)
s={link for link in r.html.absolute_links}
print(s)
    #pass
#     print(link)
'''

'''from requests_html import HTMLSession
session = HTMLSession()
site = session.get("https://www.163.com/")
public_notice_items = site.html.find('#mod_news_tab > ul > li.current > a')
# 根据id获取内容，使用 # 号连接，全部z拿回来的数据是一个list 对象
for public_notice_item in public_notice_items:
    public_notice_list = public_notice_item.find('a')
    for item in public_notice_list:
        print(item.text)'''
        
'''
from requests_html import HTMLSession
session = HTMLSession()
site = session.get("https://store.steampowered.com")
top_items = site.html.find('')

#sanRoot > main > div.hot-wrap_1nNog > div.theme-hot.category-item_1fzJW > div.list_1EDla
#根据class获取内容，使用 . 号连接，first = True 表示，如果第一个元素符合要求，则只返回第一个元素，拿回来的内容是一个字符串类型的对象
top_list = top_items.find('a')

#for item in top_list[::2]:
#    print(item.text) 
from pprint import pprint
pprint([i.text for i in top_list])


pprint([i.text.splitlines()[1] for i in top_list]) '''

'''from requests_html import HTMLSession 
session = HTMLSession()  
def get_contents(url):    
    session = HTMLSession()
    r = session.get(url)
    selector = '#maincontent' 
    about = r.html.find(selector, first=True)    
    filename=url.replace('/','-')    
    filename=filename.replace(':',"_")    
    filename=filename[35:-4]    
    print(filename)    
    f=open('d:/trash/'+filename+'.txt','w')    
    f.write(about.text)    
    f.close()    
    print(f'fininsh {url}')
r = session.get('https://www.w3school.com.cn/python/index.asp') 
t=r.html.absolute_links 
g={i for i in t if i.startswith("https://www.w3school.com.cn/python/")}  
for url in g:    
    get_contents(url) '''
    


from requests_html import HTMLSession
session = HTMLSession()
site = session.get("https://pic.netbian.com/")
public_notice_items = site.html.find('#main > div.slist')
# 根据id获取内容，使用 # 号连接，全部z拿回来的数据是一个list 对象
for public_notice_item in public_notice_items:
    public_notice_list = public_notice_item.find('.jpg')
    for item in public_notice_list:
        print(item.text)
