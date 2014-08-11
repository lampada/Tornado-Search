#Tornado-Search


Tornado is an ***Open Source Search Engine Framework(OSSEF)***.

It might be completed in a few years because I was learning in SZU and may not have so much time for it.

An Search Engine includes serveral modules:
###1.Spider: 
  Spider is used to crawling websites,getting urls,saving data to database.
  In Tornado, I am using dirbot(An open source spider written by python using scrapy) as the spider. 
  
###2.URL Pool
  In Google, they are using URL-Server to transport url to spider. In Tornado, for convenience, we save all the url to a
txt document.After the Spider crawling, url was saved to items.json in /crawl. get_url.cpp should be executed later to
make urls in items.json into a txt document.and then Spider will grab the url list to it's start_urls[],and then start next time.

###3.Page-Analytics
  I am writing it.

###4.Front Pages
  We are using PHP and BootStrap to finish an easy front page.
  
###5.start.bat
  This file is used to test the code temporarily.
