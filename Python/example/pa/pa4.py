# -*- coding: utf-8 -*-
"""
Created on Tue Apr 26 14:19:00 2022

@author: JK
"""

from requests_html import HTMLSession

session = HTMLSession()
url="https://pic.netbian.com/4kdongman"#域名获取
url9="https://pic.netbian.com"#主机获取
r = session.get(url)
selector='#main > div.slist'#selector

about = r.html.find(selector, first=True)
img_Elements=about.find('img')#图片类型
img_url_lst=[url9+i.attrs['src'] for i in img_Elements]

for img_url in img_url_lst:
    
    name = './pic/'+img_url.split('/')[-1]#路径可改
    f = open(name,'wb')#打开文件
    f.write(session.get(img_url).content)#写到本地
    f.close() #关文件
