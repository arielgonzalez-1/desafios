#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import socket as s

if __name__ == '__main__':
    server = s.socket(s.AF_INET, s.SOCK_STREAM)
    host = s.gethostname()
    port = 12345
    server.bind((host, port))
    server.listen(5)

    while True:
        clientsocket,addr = server.accept()
        print(f'Got a connection from {str(addr)}')
        msg='bienvenido al servidor'
        clientsocket.send(msg.encode('ascii'))
        clientsocket.close()
