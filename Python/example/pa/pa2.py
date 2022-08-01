# -*- coding: utf-8 -*-
"""
Created on Tue Apr 26 13:10:09 2022

@author: JK
"""





from requests_html import HTMLSession
session = HTMLSession()

def get_python3_urls(startPageUrl):
    r = session.get(startPageUrl)
    return[i for i in r.html.absolute_links if 'python3' in i]

def url2file(url):
    content_big5 = session.get(url).html.text
    from zhconv import convert
    contents_cn = convert(content_big5,'zh-cn')
    file_name = url.split('/')[-1].split('.')[0]+'.txt'
    print(contents_cn,file=open(file_name,'w',encoding='utf-8'))
    print(file_name,'done!')
    return file_name
    
if __name__ == "__main__":
    startPageUrl = 'https://www.itread01.com/study/python3-tutorial.html'
    result = list(map(url2file,get_python3_urls(startPageUrl)))
    print(result)

