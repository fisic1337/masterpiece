#!/usr/bin/env python
# -*- coding: utf-8 -*-s

import socket
import sys
import os
import time
from threading import Thread

threads = []
timeout = 0.5

os.system("clear")

print('''

\033[1;32m ███    ███\033[39m                   
\033[1;32m ████  ████\033[39m                
\033[1;32m ██ ████ ██  ██████\033[39m          
\033[1;32m ██  ██  ██       ██    ██ \033[39m   ┌─┐┌─┐┬─┐┌┬┐  ┌─┐┌─┐┌─┐┌┐┌┌┐┌┌─┐┬─┐
\033[1;32m ██      ██   █████   ██████\033[39m  ├─┘│ │├┬┘ │   └─┐│  ├─┤││││││├┤ ├┬┘
\033[1;32m                  ██    ██\033[39m    ┴  └─┘┴└─ ┴   └─┘└─┘┴ ┴┘└┘┘└┘└─┘┴└─
\033[1;32m             ██████\033[39m 
                                                                                                              

 [\033[1;32mMASTERPIECE PORT SCANNER\033[39m]
 ''')


try:
   host = raw_input(" \033[96m@MasterPiec3+>\033[93m TARGET IP:\033[39m ")
   hostIP = socket.gethostbyname(host)
   startPort = int(raw_input(" \033[96m@MasterPiec3+>\033[93m PORT TO START THE SCAN:\033[39m "))
   endPort = int(raw_input(" \033[96m@MasterPiec3+>\033[93m PORT TO END THE SCAN:\033[39m "))
   time.sleep(1)
   print " \033[96m@MasterPiec3+>\033[93m CONNECTING TO TARGET:\033[39m", hostIP
   time.sleep(1)
   print " \033[96m@MasterPiec3+>\033[1;32m CONNECTED!\033[39m"
   time.sleep(1)

except KeyboardInterrupt:
    print "\n \033[96m@MasterPiec3+>\033[31m USER INTERRUPTED! EXITING...\033[39m"
    sys.exit()

except socket.gaierror:
    print "\n \033[96m@MasterPiec3+>\033[31m BAD HOSTNAME!\033[39m"
    sys.exit()

except socket.error:
    print "\n \033[96m@MasterPiec3+>\033[31m UNABLE TO CONNECT TO TARGET!\033[39m"
    sys.exit()

print ""
print " \033[96m@MasterPiec3+>\033[93m SCANNING TARGET:\033[39m", hostIP
print ""

def scanner(port):
    	sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	socket.setdefaulttimeout(timeout)
	result = sock.connect_ex((hostIP, port))
	if result == 0:
	    print " \033[96m@MasterPiec3+>\033[93m PORT {}: \033[1;32mIS OPEN!\033[39m".format(port)
	sock.close()

for i in range(startPort, endPort+1):
	thread = Thread(target=scanner, args=(i,))
	threads.append(thread)
	thread.start()

[x.join() for x in threads]

print ""
print " \033[96m@MasterPiec3+>\033[1;32m SCAN COMPLETED!\033[39m"
print ""
time.sleep(20)

