# -*- coding: utf-8 -*-
"""
Created on Wed Apr 27 08:09:51 2022

@author: JK
"""
from requests_html import HTMLSession
session = HTMLSession()
url = 'https://minecraft.fandom.com/zh/wiki/%E6%95%99%E7%A8%8B/NBT%E4%B8%8EJSON'
site = session.get(url)
selector = 'body > div.main-container > div.resizable-container > div.page.has-right-rail > main'
items=site.html.find(selector)
for item in items :
    list1 = item.find('a')
    f = open("./NBT_and_JSON.txt","w",encoding = 'utf-8')
    f.write(item.text)
    f.close()

