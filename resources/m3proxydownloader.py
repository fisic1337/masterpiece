# -*- coding: utf-8 -*-

import requests
import time
import os
from sty import fg, rs, bg


print('''
\033[1;32m ███    ███                  
\033[1;32m ████  ████\033[39m                
\033[1;32m ██ ████ ██  ██████\033[39m          
\033[1;32m ██  ██  ██       ██    ██ \033[39m   ┌─┐┬─┐┌─┐─┐ ┬┬ ┬┌─┐
\033[1;32m ██      ██   █████   ██████\033[39m  ├─┘├┬┘│ │┌┴┬┘└┬┘└─┐ 
\033[1;32m                  ██    ██\033[39m    ┴  ┴└─└─┘┴ └─ ┴ └─┘
\033[1;32m             ██████\033[39m 
                                                                                                              

 [\033[1;32mMASTERPIECE PROXY DOWNLOADER\033[39m - BY FISIC]
 ''')

Counter = 0

Type = input(" \033[96m@MasterPiec3+>\033[93m PRESS ENTER TO DOWNLOAD HTTP PROXYS\033[39m")
param = {"type" : Type}
r = requests.get("https://www.proxy-list.download/api/v1/get", params={"type":"http"})

if os.path.exists('proxy.txt'):
  os.remove('proxy.txt')
  file = open("proxy.txt", "w")
  file.write(r.text)
  file = open("proxy.txt","r") 
  
  Content = file.read() 
  CoList = Content.split("\n") 

  for i in CoList: 
    if i: 
        Counter += 1
          
print(" \033[96m@MasterPiec3+>\033[93m PROXYS DOWNLOADED \033[31m{0}\033[39m".format(Counter)) 
print ("")
print(" \033[96m@MasterPiec3+>\033[93m PROXYS SAVED IN [proxy.txt]\033[39m")
print ("")
time.sleep(30)

