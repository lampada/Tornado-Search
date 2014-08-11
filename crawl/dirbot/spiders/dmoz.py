from scrapy.spider import Spider
from scrapy.selector import Selector

from dirbot.items import Website




class DmozSpider(Spider):
    name = "dmoz"
    allowed_domains = ["dmoz.org"]
    start_urls=[]
    f = open("D:\Tornado Search\URL Server\url_list.txt")
    line = f.readline()
    while line:
        start_urls.append(line)
        line = f.readline()
    f.close()

    def parse(self, response):
        """
        The lines below is a spider contract. For more info see:
        http://doc.scrapy.org/en/latest/topics/contracts.html

        @url http://www.dmoz.org/Computers/Programming/Languages/Python/Resources/
        @scrapes name
        """

        sel = Selector(response)
        sites = sel.xpath('//ul[@class="directory-url"]/li')
        items = []

        for site in sites:
            item = Website()
            item['name'] = 0
            item['url'] = site.xpath('a/@href').extract()
            item['description'] = 0
            items.append(item)

        return items
