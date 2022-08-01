from requests_html import HTMLSession
session = HTMLSession()
url ='http://www.shnu.edu.cn/xsxx1/list.htm'
site = session.get(url)
selector ='#l-container > div > div > div.col_news > div > div.col_news_con > div'
items=site.html.find(selector)
print(items)
for item in items :
    list1 = item.find('a')
    f = open("./test.txt","w",encoding = 'utf-8')
    f.write(item.text)
    f.close()

