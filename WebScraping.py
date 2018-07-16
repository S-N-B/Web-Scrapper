from urllib.request import urlopen
from bs4 import BeautifulSoup
htmlsource=urlopen("https://www.reddit.com/r/Futurology/comments/8bguzb/tesla_ceo_elon_musk_says_social_media_artificial/#bottom-comments")
#print(htmlsource.read())
bsObj=BeautifulSoup(htmlsource,"lxml")
comments=bsObj.findAll("p")
file=open("AI.txt","w")
for s in comments:
	file.write(s.get_text()+"\n")
file.close()
#print(comments.get_text())
