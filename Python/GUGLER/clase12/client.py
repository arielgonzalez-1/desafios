#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import socket as s

if __name__ == '__main__':
    server = s.socket(s.AF_INET, s.SOCK_STREAM)
    host = s.gethostname()
    port = 12345
    server.connect((host, port))
    msg = server.recv(1024)
    server.close()
    print(msg.decode('ascii'))