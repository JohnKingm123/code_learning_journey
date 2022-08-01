# -*- coding: utf-8 -*-
"""
Created on Tue Apr 26 13:56:13 2022

@author: JK
"""

'''https://pic.netbian.com/ 爬图片

from requests_html import HTMLSession
session = HTMLSession()

r = session.get("'https://pic.netbian.com/")
public_notice_items = site.html.find('#main > div.slist')

'''
from requests_html import HTMLSession
session = HTMLSession()
url="https://pic.netbian.com/4kdongman/"
r = session.get(url)
selector='#main > div.slist'
about = r.html.find(selector, first=True)
img_Elements=about.find('img')
img_url_lst=[url+i.attrs['src'] for i in img_Elements]
for img_url in img_url_lst:
    name ="./pic/"+img_url.split('/')[-1]
    f = open(name,'wb')
    f.write(session.get(img_url).content)
    print(f'downloaded file:{name} ')
    f.close() 