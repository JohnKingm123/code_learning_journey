from requests_html import HTMLSession
session = HTMLSession()
url = 'https://news.sohu.com/'
site = session.get(url)
selector ='body > div.wrapper-box > div.main-news-wrap > div.contentA.public.area.clearfix > div.main.left > div > div.main-right.right'
items=site.html.find(selector)
print(items)
for item in items :
    list1 = item.find('a')
    f = open("./test.txt","w",encoding = 'utf-8')
    f.write(item.text)
    f.close()

